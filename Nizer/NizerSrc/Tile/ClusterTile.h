#ifndef CLUSTERTILE_H
#define CLUSTERTILE_H

#include "Tile.h"

#include <QImage>
#include <QWidget>

#include <HashAlgorithm/Hash.h>

class ClusterTile : public Tile
{
    Q_OBJECT

public:
    ClusterTile(const std::string& name, Hash clusterHash, QWidget *parent = nullptr);

    std::size_t size() const;
    std::vector<std::string> filePaths() const;
    void addFilePath(const std::string filePath);
    QImage thumbnail() const override;
    Hash getHash() const;

private:
    std::vector<std::string> mFilePaths;
    Hash mClusterHash;
    static const QImage mThumbnail;
};

#endif // CLUSTERTILE_H
