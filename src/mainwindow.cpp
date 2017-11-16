#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initGUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initGUI()
{
    auto newAct = new QAction("&New", this);
    auto openAct = new QAction("&Open", this);
    auto saveAct = new QAction("&Save", this);
    auto saveAsAct = new QAction("&SaveAs", this);

    auto quitAct = new QAction("&Quit", this);

    auto undoAct = new QAction("&Undo", this);
    auto redoAct = new QAction("&Redo", this);

    auto cutAct = new QAction("&Cut", this);
    auto copyAct = new QAction("&Copy", this);
    auto pasteAct = new QAction("&Paste", this);

    auto preferencesAct = new QAction("&Preferences", this);

    auto fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    auto editMenu = menuBar()->addMenu("&Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();
    editMenu->addAction(preferencesAct);

    auto window = menuBar()->addMenu("&Window");

    auto helpMenu = menuBar()->addMenu("&Help");

    statusBar()->addWidget(new QLabel("Test", this));
    m_assetBrowser = new STAssetBrowser();
    auto assetDockWidget = new QDockWidget("Assets", this);
    assetDockWidget->setWidget(m_assetBrowser);

    auto outliner = new QDockWidget("Outline", this);

    auto inspector = new QDockWidget("Inspector", this);

    m_viewport = new STViewport(this);
    setCentralWidget(m_viewport);

    addDockWidget(Qt::BottomDockWidgetArea, assetDockWidget, Qt::Horizontal);
    addDockWidget(Qt::RightDockWidgetArea, inspector);
    addDockWidget(Qt::LeftDockWidgetArea, outliner);
}
