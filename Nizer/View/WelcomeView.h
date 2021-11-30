#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include "View.h"

#include <Tile/Tile.h>
#include <HashAlgorithm/HashAlgorithm.h>

class WelcomeView : public View
{
public:
    std::vector<Tile> loadFromFile;
    std::vector<Tile> loadFromFolder();
    void selectAlgorithmClick();

private:
    std::unique_ptr<HashAlgorithm> mHashAlgorithm;
};

#endif // WELCOMEVIEW_H
