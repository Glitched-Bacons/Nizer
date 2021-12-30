#include "FlowLayout.h"
#include "FlowWidget.h"

FlowWidget::FlowWidget(QWidget *parent) : QWidget(parent)
{
    flowLayout = std::make_unique<FlowLayout>(this);

    setLayout(flowLayout.get());
}

void FlowWidget::addWidget(QWidget *widget)
{
    flowLayout->addWidget(widget);
}
