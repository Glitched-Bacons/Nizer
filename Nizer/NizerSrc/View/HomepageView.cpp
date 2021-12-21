#include "HomepageView.h"
#include "ViewStack.h"
#include <QMessageBox>
#include <QPropertyAnimation>

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

    for(auto& cluster : testClusters)
        ui->gridLayout->addWidget(cluster.get());

    connect(ui->Btn_toggle, &QPushButton::clicked, this, &HomepageView::slideOutPanel);
}

void HomepageView::saveLayout()
{

}

void HomepageView::displayAboutUs()
{

}

void HomepageView::startNewSession()
{

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
