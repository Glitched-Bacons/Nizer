#include "Tile.h"

Tile::Tile(const std::string &name)
    : mName(name)
{

}

std::string Tile::name() const
{
    return mName;
}
