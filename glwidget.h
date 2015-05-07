#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QTimer>

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
    floorGrid floor;

/*signals:

public slots:
*/
};

#endif // GLWIDGET_H
