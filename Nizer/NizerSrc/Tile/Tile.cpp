#include "Tile.h"
#include "ui_Tile.h"

Tile::Tile(const std::string &name, QWidget *parent)
    : QWidget(parent)
    , ui(std::make_unique<Ui::Tile>())
    , mName(name)
{
    ui->setupUi(this);
    ui->fileName->setText(QString(name.c_str()));
}

std::string Tile::name() const
{
    return mName;
}

void Tile::setOnClickFunction(std::function<void ()> func)
{
    connect(ui->click, &QPushButton::clicked, this, func);
}

Tile::~Tile()
{

}
