//Main window for Santak application.

#include "SantakWindow.h"
#include <QPushButton>

SantakWindow::SantakWindow(QWidget *parent) :
 QWidget(parent) {

   // Set size of the window
   setFixedSize(300, 300);

   search_button = new QPushButton("Search", this);
   search_button->move(100, 270);

   clear_button = new QPushButton("Clear", this);
   clear_button->move(0, 270);
 }
