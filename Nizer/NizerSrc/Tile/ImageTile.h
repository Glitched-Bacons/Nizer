#ifndef IMAGETILE_H
#define IMAGETILE_H

#include "Tile.h"
#include "./ui_ImageTile.h"

#include <QWidget>

namespace Ui {
class ImageTile;
}

class ImageTile : public QWidget, public Tile
{
    Q_OBJECT

public:
    ImageTile(const std::string& name, const std::string& imagePath,
              QWidget *parent = nullptr);

    std::string imagePath() const;
    QImage thumbnail() const override;

private:
    std::unique_ptr<Ui::ImageTile> ui;
    QImage mThumbnail;
    std::string mImagePath;
};

#endif // IMAGETILE_H
