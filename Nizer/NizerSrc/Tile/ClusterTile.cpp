#include "ClusterTile.h"

const QImage ClusterTile::mThumbnail(":resources/icons/folder-icon.png");

ClusterTile::ClusterTile(const std::string& name, QWidget *parent)
    : Tile(name)
    , QWidget(parent)
    , ui(std::make_unique<Ui::ClusterTile>())
{
    ui->setupUi(this);
    ui->clusterName->setText(Tile::name().c_str());
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