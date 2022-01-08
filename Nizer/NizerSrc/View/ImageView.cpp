#include "ImageView.h"
#include <iostream>

ImageView::ImageView(ViewStack& viewStack, ImageTile& image, QWidget *parent) :
    View(viewStack, parent),
    ui(std::make_unique<Ui::ImageView>()),
    mImage(image)
{
    ui->setupUi(this);
    ui->annotationTextField->setVisible(false);

    connect(ui->goBackButton, &QPushButton::clicked, this, [this](){
        requestPop();
        executeRequests();
    });

    ui->nameOfFile->setText(QString(mImage.name().c_str()));
    ui->image->setPixmap(QPixmap(mImage.imagePath().c_str()));
    ui->path->setText(("Path:   " + mImage.imagePath()).c_str());
}
