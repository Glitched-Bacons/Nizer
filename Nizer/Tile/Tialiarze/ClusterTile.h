#ifndef CLUSTERTILE_H
#define CLUSTERTILE_H

#include "Tile.h"

#include <string>
#include <vector>

class ClusterTile : public Tile
{
public:
    ClusterTile(const std::string& name);

    std::size_t size() const;
    std::vector<std::string> filePaths() const;
    void addFilePath(const std::string filePath);
    QImage thumbnail() const override;

private:
    std::vector<std::string> mFilePaths;
    static const QImage mThumbnail;
};

#endif // CLUSTERTILE_H
