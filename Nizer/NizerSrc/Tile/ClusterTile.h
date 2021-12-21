#ifndef CLUSTERTILE_H
#define CLUSTERTILE_H

#include "Tile.h"
#include "./ui_ClusterTile.h"

#include <QImage>
#include <QWidget>

namespace Ui {
class ClusterTile;
}

class ClusterTile : public QWidget, public Tile
{
    Q_OBJECT

public:
    ClusterTile(const std::string& name, QWidget *parent = nullptr);
    std::size_t size() const;
    std::vector<std::string> filePaths() const;
    void addFilePath(const std::string filePath);
    QImage thumbnail() const override;

private:
    std::unique_ptr<Ui::ClusterTile> ui;
    std::vector<std::string> mFilePaths;
    static const QImage mThumbnail;
};

#endif // CLUSTERTILE_H
