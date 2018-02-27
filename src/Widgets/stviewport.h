#ifndef STVIEWPORT_H
#define STVIEWPORT_H

#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

/**
 * @brief The STViewport class
 */
class STViewport : public QOpenGLWidget
{
    Q_OBJECT
public:
    STViewport(QWidget* parent = 0);
protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool m_isLeftMouseDown;
    bool m_isRightMouseDown;
    QOpenGLFunctions* gl;
    bool m_core;
};

#endif // STVIEWPORT_H
