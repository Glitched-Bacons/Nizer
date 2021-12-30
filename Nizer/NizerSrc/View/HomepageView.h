#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H

#include "View.h"

#include <Tile/Tile.h>
#include "./ui_HomepageView.h"
#include "ViewStack.h"
#include <qpropertyanimation.h>
#include <Tile/ClusterTile.h>

QT_BEGIN_NAMESPACE
namespace Ui { class HomepageView; }
QT_END_NAMESPACE

class HomepageView : public View
{

public:
    HomepageView(ViewStack& viewStack, std::vector<std::unique_ptr<Tile>> tile, QWidget *parent = nullptr);
    void saveLayout();
    void displayAboutUs();
    void startNewSession();
    void exitApplication();

private slots:
    void slideOutPanel();

private:
    std::unique_ptr<QPropertyAnimation> mLeftMenuAnimation;
    std::vector<std::unique_ptr<ClusterTile>> testClusters;

    std::unique_ptr<Ui::HomepageView> ui;
    std::vector<std::unique_ptr<Tile>> mTiles;
};

#endif // HOMEPAGEVIEW_H
