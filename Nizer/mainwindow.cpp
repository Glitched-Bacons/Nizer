#include "mainwindow.h"
#include <View/WelcomeView.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mViewStack(*this)
{
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    mViewStack.push<WelcomeView>();
    mViewStack.applyOperations();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    mViewStack.adjustSize();
}
