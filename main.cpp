#include <QApplication>
#include <QPushButton>
#include <iostream>
#include "SantakWindow.h"

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 SantakWindow window;

 window.show();

 return app.exec();
}
