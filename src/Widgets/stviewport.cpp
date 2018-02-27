#include "stviewport.h"

STViewport::STViewport(QWidget* parent) : QOpenGLWidget(parent)
{
    m_isLeftMouseDown = false;
    m_isRightMouseDown = false;
    m_core = QSurfaceFormat::defaultFormat().profile() == QSurfaceFormat::CoreProfile;
    qDebug() << "Using Core Profile" << endl;
    setMinimumSize(800, 600);
}

/**
 * Initialize GL
 * @brief STViewport::initializeGL
 */
void STViewport::initializeGL()
{
    gl = new QOpenGLFunctions(this->context());

}

/**
 * @brief STViewport::resizeGL
 * @param w
 * @param h
 */
void STViewport::resizeGL(int w, int h)
{

}

/**
 * Actual Painting done here.
 * @brief STViewport::paintGL
 */
void STViewport::paintGL()
{
    gl->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gl->glClearColor(0.f, 0.f, 0.128f, 1.0f);
}

void STViewport::mousePressEvent(QMouseEvent *event)
{
    if(!m_isLeftMouseDown && event->button() == Qt::LeftButton){
        m_isLeftMouseDown = true;
    }

    if(!m_isRightMouseDown && event->button() == Qt::RightButton){
        m_isRightMouseDown = true;
    }
}

void STViewport::mouseMoveEvent(QMouseEvent *event)
{

}

void STViewport::mouseReleaseEvent(QMouseEvent *event)
{
    if(m_isLeftMouseDown && event->button() == Qt::LeftButton){
        m_isLeftMouseDown = false;
    }

    if(m_isRightMouseDown && event->button() == Qt::RightButton){
        m_isRightMouseDown = false;
    }
}
