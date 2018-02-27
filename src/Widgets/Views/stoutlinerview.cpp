#include "stoutlinerview.h"

STOutlinerView::STOutlinerView(QWidget *parent) : QWidget(parent)
{
    initGUI();
}

/**
 * @brief STOutlinerView::initGUI
 * Initializes the GUI for outliner
 */
void STOutlinerView::initGUI()
{
    m_objectsList = new QListWidget(this);
    m_objectsList->setAcceptDrops(false);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addWidget(m_objectsList);

    setLayout(centralLayout);
}
