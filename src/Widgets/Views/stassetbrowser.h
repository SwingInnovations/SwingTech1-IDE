#ifndef STASSETBROWSER_H
#define STASSETBROWSER_H

#include <QDockWidget>
#include <QWidget>
#include <QListWidget>
#include <QFileSystemModel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>

class STAssetBrowser : public QWidget
{
    Q_OBJECT
public:
    STAssetBrowser(QWidget* parent = 0);
private slots:
    void model_directoryLoaded(QString);
    void updateRoot(QString);
    void changeRoot();
private:
    void initGUI();
    QFileSystemModel* m_fsModel;
    QListView*        m_listView;
};

#endif // STASSETBROWSER_H
