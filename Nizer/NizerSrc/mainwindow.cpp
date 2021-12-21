#include "mainwindow.h"
#include <View/WelcomeView.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mViewStack(*this)
{
    //setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    //layout()->setSizeConstraint( QLayout::SetFixedSize );
    mViewStack.push<WelcomeView>();
    mViewStack.applyOperations();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    mViewStack.adjustSize();
}
