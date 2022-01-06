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
    widget->setVisible(true);
    setLayout(flowLayout.get());
}

void FlowWidget::clear()
{
    while (QLayoutItem* item = flowLayout->takeAt(0))
    {
        if (QWidget* widget = item->widget())
        {
            flowLayout->removeWidget(widget);
            widget->setVisible(false);
        }

        flowLayout->removeItem(item);
    }
    setLayout(flowLayout.get());
}
