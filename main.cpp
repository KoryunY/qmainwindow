#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        QMainWindow w;
        QLabel *central_widget = new QLabel("Central Widget");
        central_widget->setAlignment(Qt::AlignCenter);
        w.setCentralWidget(central_widget);

        QDockWidget *dock = new QDockWidget("Widget");
        w.addDockWidget(Qt::LeftDockWidgetArea, dock);
        dock->setWidget(new QTextEdit);

        QToolBar *toolBar=new QToolBar("toolBar",central_widget);
        toolBar->addAction("someAction");
        w.addToolBar(Qt::TopToolBarArea,toolBar);

        QMenuBar *menuBar=new QMenuBar(central_widget);
        menuBar->addAction("MenuAction");
        w.setMenuBar(menuBar);

        QStatusBar *statusBar=new QStatusBar(central_widget);
        statusBar->showMessage("Status");
        w.setStatusBar(statusBar);

        w.show();
        return a.exec();
}
