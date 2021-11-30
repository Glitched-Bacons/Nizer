#ifndef TILE_H
#define TILE_H

#include <QImage>
#include <string>

class Tile
{
public:
    virtual ~Tile() = 0;
    Tile(const std::string& name);

    std::string name() const;
    virtual QImage thumbnail() const = 0;

private:
    std::string mName;
};

#endif // TILE_H
