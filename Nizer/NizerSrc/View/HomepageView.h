#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H

#include "View.h"

#include <Tile/ImageTile.h>
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
    HomepageView(ViewStack& viewStack, std::vector<std::unique_ptr<ClusterTile>> tiles, QWidget *parent = nullptr);
    void saveLayout();
    void displayAboutUs();
    void startNewSession();
    void exitApplication();

private slots:
    void slideOutPanel();

private:
    void displayImages();
    void displayClusters();

private:
    std::unique_ptr<QPropertyAnimation> mLeftMenuAnimation;

    std::unique_ptr<Ui::HomepageView> ui;
    std::vector<std::unique_ptr<ClusterTile>> mClusters;
    std::vector<std::unique_ptr<ImageTile>> mImages;
};

#endif // HOMEPAGEVIEW_H
