#include <mainwindow.h>
#include "ViewStack.h"
#include "View.h"
#include "ui_MainWindow.h"

ViewStack::ViewStack(MainWindow& window)
    : mWindow(window)
    , mStackWidget(&window)
{
    mWindow.setCentralWidget(&mStackWidget);
}

void ViewStack::pop()
{
    mOperationsQueue.emplace_back(Operation::Pop);
}

void ViewStack::clear()
{
    mOperationsQueue.emplace_back(Operation::Clear);
}

void ViewStack::applyOperations()
{
    for(auto& change : mOperationsQueue)
    {
        switch(change.operation)
        {
        case ViewStack::Operation::Pop:
            if(mStack.empty())
                throw std::runtime_error("Can't pop as stack is empty!");
            mStackWidget.removeWidget(mStack.back().get());
            mStack.pop_back();
            break;
        case ViewStack::Operation::Push:
            if(change.createFunc == nullptr)
                throw std::runtime_error("Create func is empty for a push!");
            mStack.push_back(change.createFunc());
            mStackWidget.addWidget(mStack.back().get());
            break;
        case ViewStack::Operation::Clear:
            for(int widgetIndex = 0; widgetIndex < mStackWidget.count(); ++widgetIndex)
            {
                mStackWidget.removeWidget(mStackWidget.widget(widgetIndex));
            }
            mStack.clear();
            break;
        }
    }
    mOperationsQueue.clear();
    if(!mStack.empty())
    {
        auto& currentWidget = mStack.back();
        mStackWidget.setCurrentWidget(currentWidget.get());
        mWindow.resize(currentWidget->size());
    }
}

void ViewStack::adjustSize()
{
    // Nothing yet
}


ViewStack::Change::Change(Operation operation, std::function<std::unique_ptr<View> ()> createFunc)
    : operation(operation)
    , createFunc(createFunc)
{

}


ViewStack::~ViewStack()
{
    mOperationsQueue.clear();
    mStackWidget.close();
    mStack.clear();
}
