#ifndef VIEWSTACK_H
#define VIEWSTACK_H

#include <QStackedWidget>

class View;

class ViewStack
{
public:
    enum class Change
    {
        Pop,
        Push,
        Clear
    };

    template <class View, typename... Args>
    void push(Args&&... args);
    void pop();
    void clear();


private:
    void applyOperations();

    std::vector<Change> mOperationsQueue;
    std::vector<std::unique_ptr<View>> mStack;
    QStackedWidget mPages;
};

#endif // VIEWSTACK_H
