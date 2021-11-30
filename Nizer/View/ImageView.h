#ifndef IMAGEVIEW_H
#define IMAGEVIEW_H

#include "View.h"

#include <QImage>

class ImageView : public View
{
public:
    void annotate();

private:
    QImage image;
};

#endif // IMAGEVIEW_H
