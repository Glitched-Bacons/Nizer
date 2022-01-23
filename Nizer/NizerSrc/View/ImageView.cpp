#include "ImageView.h"
#include <iostream>
#include <filesystem>
#include <algorithm>

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

    connect(ui->addAnnotationButton, &QPushButton::clicked, this, &ImageView::annotateButtonClick);
    connect(ui->annotationTextField, &QTextEdit::textChanged, this, [this](){
        ui->imageCaption->setText(ui->annotationTextField->toPlainText());
    });

    ui->nameOfFile->setText(QString(mImage.name().c_str()));
    ui->path->setText(("Path: " + mImage.imagePath()).c_str());
    //ui->similarity->setText("Similarity: ");
    auto fileSizeString = std::to_string(std::filesystem::file_size(mImage.imagePath()));
    ui->size->setText(("Size: " + fileSizeString + " bytes").c_str());

    ui->image->setPixmap(QPixmap(mImage.imagePath().c_str()));
    ui->image->setScaledContents(true);
    ui->image->setFixedSize(0,0);
    resizeImage();
}

void ImageView::resizeImage()
{
    QSize pixSize = ui->image->pixmap().size();
    pixSize.scale(ui->imageFrame->size(), Qt::KeepAspectRatio);
    ui->image->setFixedSize(pixSize);
}

void ImageView::resizeEvent(QResizeEvent * event) {
    QWidget::resizeEvent(event);
    resizeImage();
}

void ImageView::annotateButtonClick()
{
    auto&& isAnnotationFieldVisible = ui->annotationTextField->isVisible();
    ui->annotationTextField->setVisible(!isAnnotationFieldVisible);
}


