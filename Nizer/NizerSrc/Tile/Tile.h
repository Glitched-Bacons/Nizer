#ifndef TILE_H
#define TILE_H

#include <QImage>
#include <qwidget.h>
#include <string>

namespace Ui {
class Tile;
}

class Tile : public QWidget
{
    Q_OBJECT

public:
    virtual ~Tile();
    Tile(const std::string& name, QWidget *parent = nullptr);

    std::string name() const;
    void setOnClickFunction(std::function<void()> func);
    virtual QImage thumbnail() const = 0;

protected:
    std::unique_ptr<Ui::Tile> ui;

private:
    std::string mName;

};

#endif // TILE_H
