#ifndef SANTAKDRAWAREA_H
#define SANTAKDRAWAREA_H

#include <QWidget>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>
#include <QPaintEvent>

enum DrawingSymbol {big, small, winkel};
class SantakDrawArea : public QWidget{
  Q_OBJECT
  public:
    explicit SantakDrawArea(QWidget *parent = 0);
    void clearImage();
    QImage image;
    QColor finalColor;
    //reimplementing mouse event handlers
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    DrawingSymbol currentSymbol;
  private:
    QImage _temp;
    void _clearTemp();
    bool _isDrawing;
    int _penWidth;
    QPoint _wedgeStart;
    QColor _tempColor;
    QPainter *_painter;
    QPainter *_tempPainter;
    void _drawWinkelhaken(QPoint loc, bool temp, float width, float offset);
    void _drawWedgeTo(QPoint start, QPoint end, bool temp, float width, float offset);
};

#endif //SANTAKDRAWAREA_H
