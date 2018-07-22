#include <QApplication>
#include <QPushButton>
#include <QTextStream>
#include <iostream>
#include "SantakWindow.h"
#include <opencv2/hdf.hpp>

int main(int argc, char **argv)
{
 QApplication app (argc, argv);

 cv::Ptr<cv::hdf::HDF5> h5io = cv::hdf::open("data/hdf5/proto_20.h5");

 if (h5io->hlexists("/contours") && h5io->hlexists("imgs")){
   QTextStream(stdout) << "HDF5 looks good" << endl;
 }

 SantakWindow window;

 window.show();

 h5io->close();

 return app.exec();
}
