#include "mainwindow.h"

void MainWindow::handleTimer() {
    item->move( WINDOW_MAX_X, WINDOW_MAX_Y );
}

MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );

    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);

    //First 2 arguments are the x, y, of the upper left of the rectangle.
    //The second 2 arguments are the width and height
    //The last 2 arguments are the velocity in the x, and y, directions
    item = new BouncingRectangle( 11.0, 74.0, 20.0, 20.0, 2, 3 );
    item->setBrush( redBrush );
    scene->addItem( item );

    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X * 2, WINDOW_MAX_Y * 2 );
    view->setWindowTitle( "Graphical 8-Tile Puzzle");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
}

void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();

    //This is how we get our view displayed.
    view->show();
}

MainWindow::~MainWindow()
{
    timer->stop();
    delete timer;
    delete item;
    delete scene;
    delete view;
}

