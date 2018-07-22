#ifndef SANTAKWINDOW_H
#define SANTAKWINDOW_H

#include <QMainWindow>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

class QPushButton;
class QRadioButton;
class SantakDrawArea;
  //defining enum for the current drawing symbol
class SantakWindow : public QMainWindow
{
 Q_OBJECT
 public:
  explicit SantakWindow(QWidget *parent = 0);
  cv::Mat getMat();
 private slots:
  void slotClear();
  void slotSearch();
  void slotSwitchSymbol();
 private:
   QPushButton *clearButton;
   QPushButton *searchButton;
   QRadioButton *bigWedge;
   QRadioButton *smallWedge;
   QRadioButton *winkelhaken;

   SantakDrawArea *drawArea;

 signals:
 public slots:
};

#endif // SANTAKWINDOW_H
