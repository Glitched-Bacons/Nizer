#ifndef VIEW_H
#define VIEW_H

#include "ViewStack.h"

class View : public QWidget
{
public:
    View(ViewStack& viewStack, QWidget* parent = nullptr);
    virtual ~View() = default;

    template <class Tview, typename... Args>
    void requestPush(Args&&... args)
    {
        mViewStack.push<Tview>(std::forward<Args>(args)...);
    }

    void requestPop();
    void requestClear();
    void executeRequests();

private:
    ViewStack& mViewStack;
};

#endif // VIEW_H
