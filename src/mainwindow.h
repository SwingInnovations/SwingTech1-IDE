#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QDockWidget>
#include <QLabel>
#include <QToolBar>

#include "stsceneeditormanager.h"
#include "Widgets/stviewport.h"
#include "Widgets/Views/stoutlinerview.h"
#include "Widgets/Views/stinspectorview.h"
#include "Widgets/Views/stassetbrowser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void setToolTranslate();
    void setToolRotate();
    void setToolScale();
    void setToolNone();
private:
    void initGUI(void);
    STViewport* m_viewport;

    //Windows
    STAssetBrowser* m_assetBrowser;
    STInspectorView* m_inspectorView;
    STOutlinerView* m_outlinerView;
};

#endif // MAINWINDOW_H
