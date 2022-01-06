#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "View.h"

#include <Tile/ClusterTile.h>
#include <Tile/Tile.h>
#include <HashAlgorithm/HashAlgorithm.h>
#include <mainwindow.h>
#include "./ui_WelcomeView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WelcomeView; }
QT_END_NAMESPACE

class WelcomeView : public View
{

public:
    WelcomeView(ViewStack& viewStack);

    std::vector<std::unique_ptr<ClusterTile>> loadFromFile();
    std::vector<ClusterTile> loadFromFolder();

private slots:
    void selectAlgorithmClick();
    void threeDotsButtonClicked();

private:
    std::unique_ptr<Ui::WelcomeView> ui;
    std::vector<std::unique_ptr<ClusterTile>> loadedFiles;
};

#endif // WELCOMEVIEW_H
