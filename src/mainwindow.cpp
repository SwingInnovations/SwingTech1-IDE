#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->initGUI();
}

MainWindow::~MainWindow()
{

}

void MainWindow::setToolTranslate()
{
    STSceneEditorManager::Get()->setManipulationMode(STSceneEditorManager::ManipulationMode::MOVE);
}

void MainWindow::setToolRotate()
{
    STSceneEditorManager::Get()->setManipulationMode(STSceneEditorManager::ManipulationMode::ROTATE);
}

void MainWindow::setToolScale()
{
    STSceneEditorManager::Get()->setManipulationMode(STSceneEditorManager::ManipulationMode::SCALE);
}

void MainWindow::setToolNone()
{
    STSceneEditorManager::Get()->setManipulationMode(STSceneEditorManager::ManipulationMode::NONE);
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

    auto pointerAct = new QAction("None", this);
    auto transToolAct = new QAction("Translate", this);
    auto rotToolAct = new QAction("Rotate", this);
    auto scalToolAct = new QAction("Scale", this);

    auto playGameAct = new QAction("Play", this);
    auto pauseGameAct = new QAction("Pause", this);

    auto cutAct = new QAction("&Cut", this);
    auto copyAct = new QAction("&Copy", this);
    auto pasteAct = new QAction("&Paste", this);

    auto preferencesAct = new QAction("&Preferences", this);

	//Entity Related
	auto createEmptyEntityAct = new QAction("Empty Entity", this);
	auto createActor = new QAction("Actor", this);
	auto createDirectionalLight = new QAction("Directional Light", this);
	auto createSpotLight = new QAction("Spot Light", this);
	auto createPointLight = new QAction("Point Light", this);

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

    auto entities = menuBar()->addMenu("&Entity");
	auto createMenu = entities->addMenu("Create");
	createMenu->addAction(createEmptyEntityAct);
	createMenu->addAction(createActor);
	auto lightsMenu = createMenu->addMenu("Lights");
	lightsMenu->addAction(createDirectionalLight);
	lightsMenu->addAction(createSpotLight);
	lightsMenu->addAction(createPointLight);

    auto window = menuBar()->addMenu("&Window");

    auto helpMenu = menuBar()->addMenu("&Help");

    statusBar()->addWidget(new QLabel("Test", this));
    m_assetBrowser = new STAssetBrowser();
    m_outlinerView = new STOutlinerView(this);
    m_inspectorView = new STInspectorView(this);

    auto assetDockWidget = new QDockWidget("Assets", this);
    assetDockWidget->setWidget(m_assetBrowser);

    auto outliner = new QDockWidget("Outline", this);
    outliner->setWidget(m_outlinerView);

    auto inspector = new QDockWidget("Inspector", this);
    inspector->setWidget(m_inspectorView);

    m_viewport = new STViewport(this);
    setCentralWidget(m_viewport);

    auto mainToolBar = new QToolBar("Main", this);
    mainToolBar->addAction(undoAct);
    mainToolBar->addAction(redoAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(pointerAct);
    mainToolBar->addAction(transToolAct);
    mainToolBar->addAction(rotToolAct);
    mainToolBar->addAction(scalToolAct);
    mainToolBar->addSeparator();
    mainToolBar->addAction(playGameAct);
    mainToolBar->addAction(pauseGameAct);

    connect(pointerAct, SIGNAL(triggered(bool)), SLOT(setToolNone()));
    connect(transToolAct, SIGNAL(triggered(bool)), SLOT(setToolTranslate()));
    connect(rotToolAct, SIGNAL(triggered(bool)), SLOT(setToolRotate()));
    connect(scalToolAct, SIGNAL(triggered(bool)), SLOT(setToolScale()));

    addToolBar(mainToolBar);

    addDockWidget(Qt::BottomDockWidgetArea, assetDockWidget, Qt::Horizontal);
    addDockWidget(Qt::RightDockWidgetArea, inspector);
    addDockWidget(Qt::LeftDockWidgetArea, outliner);
}
