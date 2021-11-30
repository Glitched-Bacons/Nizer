#ifndef IMAGETILE_H
#define IMAGETILE_H

#include "Tile.h"

class ImageTile : public Tile
{
public:
    ImageTile(const std::string& name, const std::string& imagePath);

    std::string imagePath() const;
    QImage thumbnail() const override;

private:
    QImage mThumbnail;
    std::string mImagePath;
};

#endif // IMAGETILE_H
