//Main window for Santak application.

#include "SantakWindow.h"
#include <QPushButton>
#include <QRadioButton>
#include <QObject>
#include <QTextStream>
#include <QWidget>
#include <QMainWindow>
#include "SantakDrawArea.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>

SantakWindow::SantakWindow(QWidget *parent) :
 QMainWindow(parent) {

   // Set size of the window
   setFixedSize(300, 300);
   setWindowTitle("santak2");
   //create drawArea
   drawArea = new SantakDrawArea(this);
   setCentralWidget(drawArea);

   //defining search and clear buttons
   searchButton = new QPushButton("Search", this);
   searchButton->move(100, 270);

   clearButton = new QPushButton("Clear", this);
   clearButton->move(0, 270);

   //Connecting appropriate signals and slots
  connect(clearButton, SIGNAL (clicked()), this, SLOT (slotClear()));

  connect(searchButton, SIGNAL (clicked()), this, SLOT (slotSearch()));

  bigWedge = new QRadioButton("big wedge", this);
  bigWedge->move(200, 220);
  bigWedge->setChecked(true);

  connect(bigWedge, SIGNAL (clicked()), this, SLOT (slotSwitchSymbol()));

  smallWedge = new QRadioButton("small wedge", this);
  smallWedge->move(200, 240);

  connect(smallWedge, SIGNAL (clicked()), this, SLOT (slotSwitchSymbol()));

  winkelhaken = new QRadioButton("winkelhaken", this);
  winkelhaken->move(200, 260);

  connect(winkelhaken, SIGNAL (clicked()), this, SLOT (slotSwitchSymbol()));

 }

void SantakWindow::slotSwitchSymbol(){
  //gets pointer to the sender of the signal
  QObject* button = QObject::sender();
  // switches the current drawing symbol,
  //testing button identity via pointer matching
  if (button == this->bigWedge){
    this->drawArea->currentSymbol = big;
  } else if (button == this->smallWedge){
    this->drawArea->currentSymbol = small;
  } else if (button == this->winkelhaken){
    this->drawArea->currentSymbol = winkel;
  }
}

void SantakWindow::slotClear(){
  // QTextStream(stdout) << "Clear window" << endl;
  this->drawArea->clearImage();
}

cv::Mat SantakWindow::getMat(){
  //returns OpenCV image array from Qt image
  //Source: https://asmaloney.com/2013/11/code/converting-between-cvmat-and-qimage-or-qpixmap/

  cv::Mat  query( this->drawArea->image.height(), this->drawArea->image.width(),
                          CV_8UC4,
                          const_cast<uchar*>(this->drawArea->image.bits()),
                          static_cast<size_t>(this->drawArea->image.bytesPerLine())
                          );

  //clone to memory
  //converts to grayscale
  cv::Mat gray;
  cv::cvtColor(query, gray, cv::COLOR_BGR2GRAY);

  return gray;

}

void SantakWindow::slotSearch(){
  QTextStream(stdout) << "Firing up the ol' GPU" << endl;
  cv::Mat img = this->getMat();

  //saving just to test

  cv::imwrite("test.jpg", img);
}
