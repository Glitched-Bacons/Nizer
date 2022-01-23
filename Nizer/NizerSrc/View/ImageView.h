#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include <Tile/ImageTile.h>
#include "ViewStack.h"
#include "View.h"
#include "ui_ImageView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ImageView; }
QT_END_NAMESPACE

class ImageView : public View
{

public:
    ImageView(ViewStack& viewStack, ImageTile& image, QWidget *parent = nullptr);
protected:
    void resizeEvent(QResizeEvent * event);

private:
    void annotateButtonClick();

private slots:
    void resizeImage();

private:
    std::unique_ptr<Ui::ImageView> ui;
    const ImageTile& mImage;
};

#endif // IMAGEVIEW_H
