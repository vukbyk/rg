#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>
//#include <QElapsedTimer>

#include "floorgrid.h"

class GLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit GLWidget(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    QTimer timer;

//    QElapsedTimer elapsedT;
//    qint64 lastTime = 0;
//    int dt;

    floorGrid floor;

    float rotation;

/*signals:

public slots:
*/
};

#endif // GLWIDGET_H
