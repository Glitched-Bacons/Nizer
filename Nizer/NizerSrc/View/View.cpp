#include "View.h"
#include "ViewStack.h"
#include <iostream>

View::View(ViewStack &viewStack, QWidget* parent)
    : mViewStack(viewStack)
{

}

void View::requestPop()
{
    mViewStack.pop();
}

void View::requestClear()
{
    mViewStack.clear();
}

void View::executeRequests()
{
    mViewStack.applyOperations();
}
