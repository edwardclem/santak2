#include <QApplication>
#include <QPushButton>
#include <QTextStream>
#include <iostream>
#include "SantakWindow.h"
#include "SantakInferenceOpenCV.h"
#include <opencv2/hdf.hpp>

int main(int argc, char **argv)
{
  if (argc < 2){
    std::cout << "Please provide a data prefix for h5 and JSON files." << std::endl;
  } else{
    std::string prefix;
    prefix.append(argv[1]);

    SantakInferenceOpenCV inf = SantakInferenceOpenCV(prefix);

  }


  return 0;

 // QApplication app (argc, argv);
 //
 // SantakWindow window;
 //
 // window.show();
 //
 // h5io->close();
 //
 // return app.exec();
}
