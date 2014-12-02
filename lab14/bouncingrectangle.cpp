#include "bouncingrectangle.h"

BouncingRectangle::BouncingRectangle(double nx, double ny, double w, double h, int vx, int vy ) :
    QGraphicsRectItem(nx, ny, w, h) {
    x = nx;
    y = ny;
    width = w;
    height = h;
    velocityX = vx;
    velocityY = vy;
}

int BouncingRectangle::getVelocityX() {
    return velocityX;
}

int BouncingRectangle::getVelocityY() {
    return velocityY;
}

void BouncingRectangle::setVelocityX( int vx ) {
    velocityX = vx;
}

void BouncingRectangle::setVelocityY( int vy ) {
    velocityY = vy;
}

void BouncingRectangle::move( int windowMaxX, int windowMaxY ) {
    //We move by adding the velocity to the current position.
    //Then we test whether we have reached the edge of our moving space
    //If so, we reverse the velocity (y-velocity when we hit the top/bottom and
    //x-velocity when we hit the left/right sides) and undo the position change
    //that moved part of the rectangle off the screen.
    x += velocityX;
    y += velocityY;

    if ( x < 0 ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( y < 0 ) {
        velocityY = -velocityY;
        y +=velocityY;
    }

    if ( (x+width) > windowMaxX ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY ) {
         velocityY = -velocityY;
         y+=velocityY;
    }

    //Everything is good. Update the QRectF that is actually displayed.
    QPointF p( x, y );
    QRectF r( rect() );
    r.moveTo(p);
    setRect( r );
}

int BouncingRectangle::getX() {
    return x;
}

int BouncingRectangle::getY() {
    return y;
}

void BouncingRectangle::setX(int nx) {
    x = nx;
}

void BouncingRectangle::setY(int ny) {
    y = ny;
}

