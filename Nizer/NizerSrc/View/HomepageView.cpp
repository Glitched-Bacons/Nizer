#include "HomepageView.h"
#include "ViewStack.h"
#include "WelcomeView.h"
#include <QFileDialog>
#include <QGraphicsDropShadowEffect>
#include <QMessageBox>
#include <QPropertyAnimation>
#include "View/Misc/AboutUs.h"
#include <iostream>
#include <fstream>

HomepageView::HomepageView(ViewStack& viewStack, std::vector<std::unique_ptr<Tile>> tile, QWidget *parent)
    : mTiles(std::move(tile))
    , View(viewStack, parent)
    , ui(std::make_unique<Ui::HomepageView>())
{
    ui->setupUi(this);
    for(int i = 0; i < 10; ++i)
    {
        testClusters.emplace_back(std::make_unique<ClusterTile>("name" + std::to_string(i)));
    }
    viewStack.setWindowSize(QSize(0,0), QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));

    int counter = 0;
    for(auto& cluster : testClusters)
        ui->flowWidget->addWidget(cluster.get());

    connect(ui->Btn_toggle, &QPushButton::clicked, this, &HomepageView::slideOutPanel);
    connect(ui->Save_Button, &QPushButton::clicked, this, &HomepageView::saveLayout);
    connect(ui->New_Session_Button, &QPushButton::clicked, this, &HomepageView::startNewSession);
    connect(ui->About_Us_Button, &QPushButton::clicked, this, &HomepageView::displayAboutUs);
    connect(ui->Exit_Button, &QPushButton::clicked, this, &HomepageView::exitApplication);
}

void HomepageView::saveLayout()
{
    auto fileName = QFileDialog::getSaveFileName(this, "Save your session", QString(), "Nizer Files (*.nizer)");
    std::ofstream outputFile(fileName.toStdString());
    outputFile << "To be implemented" << std::endl;
    outputFile.close();
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
