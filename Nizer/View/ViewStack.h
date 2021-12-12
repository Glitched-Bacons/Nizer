#ifndef VIEWSTACK_H
#define VIEWSTACK_H

#include <QMainWindow>
#include <QStackedWidget>

class MainWindow;
class View;

class ViewStack
{
public:
    ViewStack(MainWindow& window);
    ~ViewStack();

    enum class Operation
    {
        Pop,
        Push,
        Clear
    };

    struct Change
    {
        Change(Operation operation, std::function<std::unique_ptr<View>()> createFunc = nullptr);

        Operation operation;
        std::function<std::unique_ptr<View>()> createFunc;
    };

    template <class Tview, typename... Args>
    void push(Args&&... args);

    void pop();
    void clear();
    void applyOperations();
    void adjustSize();


private:
    MainWindow& mWindow;
    std::vector<Change> mOperationsQueue;
    QStackedWidget mStackWidget;
    std::vector<std::unique_ptr<View>> mStack;
};

template <class Tview, typename... Args>
void ViewStack::push(Args&&... args)
{
    auto createFunc = [&args..., this](){
        return std::make_unique<Tview>(*this, std::forward<Args>(args)...);
    };

    mOperationsQueue.emplace_back(Operation::Push, createFunc);
}

#endif // VIEWSTACK_H
