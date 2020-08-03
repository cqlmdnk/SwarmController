#pragma once
#include <qopenglwidget.h>
#include <qopenglfunctions.h>
#include "Controller.h"

class LiveScreen : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT
public:
    LiveScreen(QWidget* parent = nullptr);

protected:
    void initializeGL();

    void resizeGL(int w, int h) ;

    void paintGL();

};