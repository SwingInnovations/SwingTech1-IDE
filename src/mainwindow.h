#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QLabel>

#include "Widgets/stviewport.h"
#include "Widgets/Views/stassetbrowser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initGUI(void);
    STViewport* m_viewport;

    //Windows
    STAssetBrowser* m_assetBrowser;
};

#endif // MAINWINDOW_H
