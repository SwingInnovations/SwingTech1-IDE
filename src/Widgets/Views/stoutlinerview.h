#ifndef STOUTLINERVIEW_H
#define STOUTLINERVIEW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>


class STOutlinerView : public QWidget
{
    Q_OBJECT
public:
    STOutlinerView(QWidget* parent = 0);
private:
    void initGUI();

    QListWidget* m_objectsList;
};

#endif // STOUTLINERVIEW_H
