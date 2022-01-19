#include "ClusterTile.h"

const QImage ClusterTile::mThumbnail(":/icons/icons/folder-icon.png");

ClusterTile::ClusterTile(const std::string& name, Hash clusterHash, QWidget *parent)
    : Tile(name, parent)
    , mClusterHash(clusterHash)
{

}

std::size_t ClusterTile::size() const
{
    return mFilePaths.size();
}

std::vector<std::string> ClusterTile::filePaths() const
{
    return mFilePaths;
}

void ClusterTile::addFilePath(const std::string filePath)
{
    mFilePaths.push_back(filePath);
}

QImage ClusterTile::thumbnail() const
{
    return mThumbnail;
}

Hash ClusterTile::getHash() const
{
    return mClusterHash;
}
