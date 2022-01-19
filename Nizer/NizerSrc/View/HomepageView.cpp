#include "HomepageView.h"
#include "ViewStack.h"
#include "WelcomeView.h"
#include "ImageView.h"
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QPropertyAnimation>
#include "View/Misc/AboutUs.h"
#include <iostream>
#include <fstream>
#include <Tile/ImageTile.h>

HomepageView::HomepageView(ViewStack& viewStack, std::vector<std::unique_ptr<ClusterTile>> tiles, QWidget *parent)
    : mClusters(std::move(tiles))
    , View(viewStack, parent)
    , ui(std::make_unique<Ui::HomepageView>())
{
    ui->setupUi(this);
    ui->goBackFrame->setVisible(false);
    viewStack.setWindowSize(QSize(0,0), QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));

    // Just for test purposes
    for(auto& cluster : mClusters)
    {
        cluster->setOnClickFunction([this, &cluster](){
            mImages.clear();
            for(const auto& filePath : cluster->filePaths())
            {
                std::string filename = filePath.substr(filePath.find_last_of("/\\") + 1);
                mImages.push_back(std::make_unique<ImageTile>(filename, filePath));
                auto& image = mImages.back();
                image->setOnClickFunction([this, &image](){
                    requestPush<ImageView>(*image);
                    executeRequests();
                });
            }
            displayImages();
        });
    }

    displayClusters();
    connect(ui->goBackButton, &QPushButton::clicked, this, &HomepageView::displayClusters);
    connect(ui->Btn_toggle, &QPushButton::clicked, this, &HomepageView::slideOutPanel);
    connect(ui->Save_Button, &QPushButton::clicked, this, &HomepageView::saveLayout);
    connect(ui->New_Session_Button, &QPushButton::clicked, this, &HomepageView::startNewSession);
    connect(ui->About_Us_Button, &QPushButton::clicked, this, &HomepageView::displayAboutUs);
    connect(ui->Exit_Button, &QPushButton::clicked, this, &HomepageView::exitApplication);
}

void HomepageView::saveLayout()
{
    QMessageBox msgBox(this);
    msgBox.setStyleSheet("color: white;");
    msgBox.setWindowTitle("Oops, not implemented!");
    msgBox.setText("Sorry, this feature is not yet implemented");
    msgBox.setWindowIcon(QIcon(":/icons/icons/bacon-icon.png"));

    QPixmap&& pixmap = QPixmap();
    pixmap.convertFromImage(QImage(":/images/images/bacon.png").scaled(100, 100, Qt::AspectRatioMode::KeepAspectRatio));
    msgBox.setIconPixmap(std::move(pixmap));
    msgBox.exec();
}

void HomepageView::displayAboutUs()
{
    AboutUs dialog(this);
    dialog.setModal(true);
    dialog.setWindowFlags(dialog.windowFlags() | Qt::FramelessWindowHint);
    dialog.window()->setAttribute(Qt::WA_TranslucentBackground);
    QGraphicsDropShadowEffect* ef = new QGraphicsDropShadowEffect;
    ef->setColor(QColor(0, 0, 0, 160));
    ef->setBlurRadius(50);
    ef->setOffset(0);
    dialog.setGraphicsEffect(ef);
    dialog.exec();
}

void HomepageView::startNewSession()
{
    requestPop();
    requestPush<WelcomeView>();
    executeRequests();
}

void HomepageView::exitApplication()
{
    QApplication::quit();
}

void HomepageView::slideOutPanel()
{
    //TODO: This whole function should be changed
    static auto minimumWidth = ui->frame_left_menu->minimumWidth();
    static auto maximumWidth = ui->frame_left_menu->maximumWidth();
    auto resizeDown = ui->frame_left_menu->minimumWidth() == maximumWidth;

    mLeftMenuAnimation = std::make_unique<QPropertyAnimation>(ui->frame_left_menu, "minimumWidth");
    mLeftMenuAnimation->setDuration(200);
    if(resizeDown){
        mLeftMenuAnimation->setStartValue(maximumWidth);
        mLeftMenuAnimation->setEndValue(minimumWidth);
    }
    else {
        mLeftMenuAnimation->setStartValue(minimumWidth);
        mLeftMenuAnimation->setEndValue(maximumWidth);
    }
    mLeftMenuAnimation->setEasingCurve(QEasingCurve::OutQuart);
    mLeftMenuAnimation->start();
    if(resizeDown)
    {
        for(auto& button : {ui->New_Session_Button, ui->About_Us_Button, ui->Save_Button, ui->Exit_Button})
            button->setText("");
    }
    else
    {
        ui->New_Session_Button->setText("Start a new session");
        ui->About_Us_Button->setText("About us");
        ui->Save_Button->setText("Save");
        ui->Exit_Button->setText("Exit");
    }
}

void HomepageView::displayImages()
{
    ui->flowWidget->clear();
    ui->goBackFrame->setVisible(true);
    for(const auto& image : mImages)
    {
        ui->flowWidget->addWidget(image.get());
    }
}

void HomepageView::displayClusters()
{
    ui->flowWidget->clear();
    ui->goBackFrame->setVisible(false);
    for(const auto& cluster : mClusters)
    {
        ui->flowWidget->addWidget(cluster.get());
    }
}
