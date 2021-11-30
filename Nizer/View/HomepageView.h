#ifndef HOMEPAGEVIEW_H
#define HOMEPAGEVIEW_H

#include "View.h"
#include <vector>
#include <Tile/Tile.h>

class HomepageView : public View
{
public:
    void open(const Tile& tile);
    void saveLayout();
    void displayAboutUs();
    void startNewSession();

private:
    std::vector<Tile> mTiles;
};

#endif // HOMEPAGEVIEW_H
