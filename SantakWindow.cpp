//Main window for Santak application.

#include "SantakWindow.h"
#include <QPushButton>
#include <QRadioButton>
#include <QObject>
#include <QTextStream>
#include <QWidget>
#include <QMainWindow>
#include "SantakDrawArea.h"


SantakWindow::SantakWindow(QWidget *parent) :
 QMainWindow(parent) {

   drawArea = new SantakDrawArea(this);

   // Set size of the window
   setFixedSize(300, 300);
   setWindowTitle("santak2");
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

void SantakWindow::slotSearch(){
  QTextStream(stdout) << "Firing up the ol' GPU" << endl;
}
