#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "View.h"

#include <Tile/ClusterTile.h>
#include <Tile/Tile.h>
#include <HashAlgorithm/AHash.h>
#include <HashAlgorithm/HashAlgorithm.h>
#include <mainwindow.h>
#include "./ui_WelcomeView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeView; }
QT_END_NAMESPACE

class WelcomeView : public View
{

public:
    WelcomeView(ViewStack& viewStack,
                std::unique_ptr<HashAlgorithm> hashAlgorithm = std::make_unique<AHash>());

    std::vector<std::unique_ptr<ClusterTile>> loadFromFile();
    std::vector<std::unique_ptr<ClusterTile>> loadFromFolder();


private: // UI functions
    void selectAlgorithmClick();
    void threeDotsButtonClicked();

private: // Additional functions
    ClusterTile& findClosestCluster(std::vector<std::unique_ptr<ClusterTile>>& clusters, const Hash& hash);
    void createNewCluster(std::vector<std::unique_ptr<ClusterTile>>& clusters,
                          const Hash& clusterHash, const std::string& initialFilePath);

private:
    std::unique_ptr<Ui::WelcomeView> ui;
    std::vector<std::unique_ptr<ClusterTile>> loadedFiles;
    std::unique_ptr<HashAlgorithm> mHashAlgorithm;
    static const std::vector<std::string> imageExtensions;
    static inline const int hashThreshold = 5;
};

#endif // WELCOMEVIEW_H
