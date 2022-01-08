#include "ImageTile.h"
#include "ui_Tile.h"

#include <QPixmap>

ImageTile::ImageTile(const std::string& name, const std::string& imagePath,
                     QWidget *parent)
    : Tile(name, parent)
    , mImagePath(imagePath)
    , mThumbnail(QString(imagePath.c_str()))
{
    mThumbnail = mThumbnail.scaled(100, 100, Qt::KeepAspectRatio);
    auto&& qpixmap = QPixmap();
    qpixmap.convertFromImage(mThumbnail);
    Tile::ui->fileImage->setPixmap(std::move(qpixmap));
}

std::string ImageTile::imagePath() const
{
    return mImagePath;
}

QImage ImageTile::thumbnail() const
{
    return mThumbnail;
}
