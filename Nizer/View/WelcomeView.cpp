#include "WelcomeView.h"

std::vector<Tile> WelcomeView::loadFromFile()
{
    return std::vector<Tile>();
}

std::vector<Tile> WelcomeView::loadFromFolder()
{
    return std::vector<Tile>();
}

void WelcomeView::selectAlgorithmClick()
{

}

void WelcomeView::threeDotsButtonClicked()
{
    ui->button_select_algorithm->setHidden(false);
}


WelcomeView::WelcomeView(ViewStack& viewStack)
    : View(viewStack)
    , ui(std::make_unique<Ui::WelcomeView>())
{
    ui->setupUi(this);
    ui->button_select_algorithm->setHidden(true);

    connect(ui->button_threedots, &QPushButton::clicked, this, [this](){
        auto newState = !ui->button_select_algorithm->isHidden();
        ui->button_select_algorithm->setHidden(newState);
    });

    connect(ui->button_select_folder, &QPushButton::clicked, this, [this](){
        requestPush<WelcomeView>();
        executeRequests();
    });

    connect(ui->button_load_saved_data, &QPushButton::clicked, this, [this](){
        requestPop();
        executeRequests();
    });

}
