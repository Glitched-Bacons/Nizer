#include "AboutUs.h"
#include "ui_AboutUs.h"

AboutUs::AboutUs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutUs)
{
    ui->setupUi(this);

    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(close()));
}

AboutUs::~AboutUs()
{
    delete ui;
}
