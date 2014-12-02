#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>

#include "bouncingrectangle.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();

    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    BouncingRectangle *item;

public slots:
    void handleTimer();

};

#endif // MAINWINDOW_H
