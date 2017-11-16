#ifndef STVIEWPORT_H
#define STVIEWPORT_H

#include <QObject>
#include <QWidget>
#include <QtOpenGL/QGLWidget>

class STViewport : public QGLWidget
{
    Q_OBJECT
public:
    STViewport(QWidget* parent = 0);
protected:
    void initializeGL();
    void resizeGL();
    void paintGL();
};

#endif // STVIEWPORT_H
