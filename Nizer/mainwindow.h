#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <View/ViewStack.h>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void resizeEvent(QResizeEvent* event) override;
    ViewStack mViewStack;
};
#endif // MAINWINDOW_H
