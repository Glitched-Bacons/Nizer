#ifndef VIEW_H
#define VIEW_H

#include "ViewStack.h"

class View
{
public:
    View(ViewStack& viewStack);
    virtual ~View() = 0;

    template <class View, typename... Args>
    void requestPush(Args&&... args);
    void requestPop();
    void requestClear();

private:
    ViewStack& mViewStack;
};

#endif // VIEW_H
