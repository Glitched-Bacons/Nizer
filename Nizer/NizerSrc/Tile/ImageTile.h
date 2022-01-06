#ifndef IMAGETILE_H
#define IMAGETILE_H

#include "Tile.h"

#include <QWidget>

class ImageTile : public Tile
{
    Q_OBJECT

public:
    ImageTile(const std::string& name, const std::string& imagePath,
              QWidget *parent = nullptr);

    std::string imagePath() const;
    QImage thumbnail() const override;

private:
    QImage mThumbnail;
    std::string mImagePath;
};

#endif // IMAGETILE_H
