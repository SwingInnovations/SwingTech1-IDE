#include "stinspectorview.h"

STInspectorView::STInspectorView(QWidget *parent) : QWidget(parent)
{
    initGUI();
}

//Initializes the GUI
void STInspectorView::initGUI()
{
    m_nameLE = new QLineEdit(this);
    m_tagsCmbx = new QComboBox(this);
    m_showDebug = new QCheckBox("Show Debug", this);

    m_transXLE = new QLineEdit(this);
    m_transYLE = new QLineEdit(this);
    m_transZLE = new QLineEdit(this);

    m_rotXLE = new QLineEdit(this);
    m_rotYLE = new QLineEdit(this);
    m_rotZLE = new QLineEdit(this);

    m_scalXLE = new QLineEdit(this);
    m_scalXLE->setText("1");
    m_scalYLE = new QLineEdit(this);
    m_scalYLE->setText("1");
    m_scalZLE = new QLineEdit(this);
    m_scalZLE->setText("1");

    //Header Box
    auto nameLbl = new QLabel("Name:", this);
    auto tagsLbl = new QLabel("Tags", this);

    auto nameHeaderLayout = new QHBoxLayout;
    nameHeaderLayout->addWidget(nameLbl);
    nameHeaderLayout->addWidget(m_nameLE);

    auto headerOptions = new QHBoxLayout;
    headerOptions->addWidget(tagsLbl);
    headerOptions->addWidget(m_tagsCmbx);
    headerOptions->addSpacerItem(new QSpacerItem(0, 0));
    headerOptions->addWidget(m_showDebug);

    auto headerLayout = new QVBoxLayout;
    headerLayout->addLayout(nameHeaderLayout);
    headerLayout->addLayout(headerOptions);

    m_addComponentBtn = new QPushButton("[+]", this);

    auto transformGrid = new QGridLayout;
    transformGrid->addWidget(new QLabel("X", this), 0, 1);
    transformGrid->addWidget(new QLabel("Y", this), 0, 2);
    transformGrid->addWidget(new QLabel("Z", this), 0, 3);

    transformGrid->addWidget(new QLabel("Translate: ", this), 1, 0);
    transformGrid->addWidget(m_transXLE, 1, 1);
    transformGrid->addWidget(m_transYLE, 1, 2);
    transformGrid->addWidget(m_transZLE, 1, 3);

    transformGrid->addWidget(new QLabel("Rotate: ", this), 2, 0);
    transformGrid->addWidget(m_rotXLE, 2, 1);
    transformGrid->addWidget(m_rotYLE, 2, 2);
    transformGrid->addWidget(m_rotZLE, 2, 3);

    transformGrid->addWidget(new QLabel("Scale: ", this), 3, 0);
    transformGrid->addWidget(m_scalXLE, 3, 1);
    transformGrid->addWidget(m_scalYLE, 3, 2);
    transformGrid->addWidget(m_scalZLE, 3, 3);

    auto centralLayout = new QVBoxLayout;
    centralLayout->addLayout(headerLayout);
    centralLayout->addLayout(transformGrid);
    centralLayout->addWidget(m_addComponentBtn, 0, Qt::AlignCenter);
    centralLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding, QSizePolicy::Expanding));

    setLayout(centralLayout);
}
