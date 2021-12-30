#ifndef FLOWWIDGET_H
#define FLOWWIDGET_H

#include "FlowLayout.h"

#include <qwidget.h>



class FlowWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FlowWidget(QWidget *parent = nullptr);
    void addWidget(QWidget* widget);

private:
    std::unique_ptr<FlowLayout> flowLayout;

};

#endif // FLOWWIDGET_H
