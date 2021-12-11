#include "ImageTile.h"

ImageTile::ImageTile(const std::string& name, const std::string& imagePath,
                     QWidget *parent)
    : Tile(name)
    , QWidget(parent)
    , mThumbnail(":resources/icons/folder-icon.png")
    , ui(std::make_unique<Ui::ImageTile>())
{
    ui->setupUi(this);
}

std::string ImageTile::imagePath() const
{
    return mImagePath;
}

QImage ImageTile::thumbnail() const
{
    return mThumbnail;
}
