#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QPolygon>
#include <QColor>
#include <QMouseEvent>
#include <QTextStream>
#include <QPainter>
#include <QRect>
#include <cmath>

#include <SantakDrawArea.h>

SantakDrawArea::SantakDrawArea(QWidget *parent):
  QWidget(parent){

    //setting up draw area parameters
    setAttribute(Qt::WA_StaticContents);
    _isDrawing = false;
    finalColor = Qt::black;
    _tempColor = Qt::gray;
    //creating and filling image
    image = QImage(parent->size(), QImage::Format_ARGB32);
    image.fill(qRgba(255, 255, 255, 255));
    _temp = QImage(parent->size(), QImage::Format_ARGB32);
    _temp.fill(qRgba(0, 0, 0, 0));

    //set up drawing symbol switching
    currentSymbol = big;
}

void SantakDrawArea::clearImage(){
    //clears the final image.
    this->image.fill(qRgba(255,255,255,255));
    this->update();
}

void SantakDrawArea::_clearTemp(){
  //clears the (transparent) temporary image
  this->_temp.fill(qRgba(0,0,0,0));
  this->update();
}

void SantakDrawArea::mousePressEvent(QMouseEvent *event){
  // QTextStream(stdout) << "Mouse Press" << endl;

  //set up for drawing operation
  this->_wedgeStart = event->pos();
  this->_isDrawing = true;
}

void SantakDrawArea::mouseMoveEvent(QMouseEvent *event){
  // QTextStream(stdout) << "mouse move" << endl;
  this->_clearTemp();
  //Draw a temporary wedge on the screen
  if (this->currentSymbol == big){
    //TODO: add offset and width as class props
    this->_drawWedgeTo(this->_wedgeStart, event->pos(), true, 10, 30);
  } else if (this->currentSymbol == small){
    this->_drawWedgeTo(this->_wedgeStart, event->pos(), true, 5, 15);
  } else if (this->currentSymbol == winkel){
    this->_drawWinkelhaken(event->pos(), true, 10, 20);
  }

}

void SantakDrawArea::mouseReleaseEvent(QMouseEvent *event){
  // QTextStream(stdout) << "Mouse release" << endl;
  this->_clearTemp();
  //draw the final wedge
  if (this->currentSymbol == big){
    this->_drawWedgeTo(this->_wedgeStart, event->pos(), false, 10, 30);

  } else if (this->currentSymbol == small){
    this->_drawWedgeTo(this->_wedgeStart, event->pos(), false, 5, 15);
  } else if (this->currentSymbol == winkel){
    this->_drawWinkelhaken(event->pos(), false, 10, 30);
  }
  this->_isDrawing = false;
}


void SantakDrawArea::_drawWinkelhaken(QPoint loc, bool temp, float width, float offset){

  QPoint point1 = QPoint(offset/2, offset);
  QPoint point2 = QPoint(offset/2, -offset);
  QPoint point3 = QPoint(-offset/2, 0);

  QPolygon poly;
  //using QVector streaming operator
  poly << point1 << point2 << point3;

  //TODO: refactor this

  QImage *img;
  QColor color;

  if (temp){
    img = &this->_temp;
    color = this->_tempColor;

  } else{
    img = &this->image;
    color = this->finalColor;
  }
  QPainter painter(img);
  painter.setPen(QPen(color, width));
  painter.setBrush(QBrush(QColor(255,255,255,255)));
  painter.translate(loc);
  painter.drawPolygon(poly);

  //TODO: Update only limited section of widget
  this->update();

}

void SantakDrawArea::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    const QRect dirtyRect = event->rect();
    painter.drawImage(dirtyRect, this->image, dirtyRect);
    painter.drawImage(dirtyRect, this->_temp, dirtyRect);

}

void SantakDrawArea::_drawWedgeTo(QPoint start, QPoint end, bool temp, float width, float offset){
  //draws a wedge from the provided start point to the provided end point.
  QPoint point1 = QPoint(-offset, -offset);
  QPoint point2 = QPoint(offset, -offset);
  QPoint point3 = QPoint(0, offset/2);

  QPolygon poly;
  //using QVector streaming operator
  poly << point1 << point2 << point3;

  //computing orientation vector from points
  QPoint diff = end - start;
  float length = hypot(diff.x(), diff.y());
  //convering to degrees
  float angle = atan2(diff.x(), diff.y())*180./M_PI;

  //transform painter
  QImage *img;
  QColor color;

  if (temp){
    img = &this->_temp;
    color = this->_tempColor;
  } else{
    img = &this->image;
    color = this->finalColor;
  }

  QPainter painter(img);
  painter.setPen(QPen(color, width));
  painter.setBrush(QBrush(QColor(255,255,255,255)));

  painter.translate(start);
  painter.rotate(-angle);
  painter.drawPolygon(poly);

  if (length > 10){
    painter.drawLine(point3, QPoint(0, length));
  }
  this->update();
}
