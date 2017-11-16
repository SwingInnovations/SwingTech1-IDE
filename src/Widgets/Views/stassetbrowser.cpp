#include "stassetbrowser.h"

STAssetBrowser::STAssetBrowser(QWidget *parent)
{
    initGUI();
}

void STAssetBrowser::model_directoryLoaded(QString path)
{
    m_fsModel->sort(0, Qt::AscendingOrder);
    m_listView->setCurrentIndex(m_fsModel->index(0, 0, m_listView->rootIndex()));
}

void STAssetBrowser::updateRoot(QString path)
{
    m_fsModel->setRootPath(path);
    m_fsModel->sort(0, Qt::AscendingOrder);
    m_listView->setRootIndex(m_fsModel->index(path));
}

void STAssetBrowser::changeRoot()
{
    m_fsModel->setRootPath("/home/ndanque");
    m_listView->setRootIndex(m_fsModel->index("/home/ndanque"));
}

void STAssetBrowser::initGUI()
{
    m_fsModel = new QFileSystemModel(this);
    m_fsModel->setRootPath("/home/ndanque");

    m_listView = new QListView();
    m_listView->setModel(m_fsModel);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_listView);
    setLayout(centralLayout);

    connect(m_fsModel, SIGNAL(directoryLoaded(QString)), SLOT(model_directoryLoaded(QString)));
    //connect(m_listView, SIGNAL()
    QTimer::singleShot(1000, this, SLOT(changeRoot()));
}
