#ifndef STINSPECTORVIEW_H
#define STINSPECTORVIEW_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>

class STInspectorView : public QWidget
{
public:
    STInspectorView(QWidget* parent = 0);
private slots:

private:
    void initGUI();

    QLineEdit*  m_nameLE;
    QComboBox*  m_tagsCmbx;
    QCheckBox*  m_showDebug;

    QLineEdit*  m_transXLE;
    QLineEdit*  m_transYLE;
    QLineEdit*  m_transZLE;

    QLineEdit*  m_rotXLE;
    QLineEdit*  m_rotYLE;
    QLineEdit*  m_rotZLE;

    QLineEdit*  m_scalXLE;
    QLineEdit*  m_scalYLE;
    QLineEdit*  m_scalZLE;

    QPushButton*    m_addComponentBtn;
};

#endif // STINSPECTORVIEW_H
