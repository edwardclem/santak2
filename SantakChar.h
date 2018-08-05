//holding all information about one character
//built from hdf5 data file provided to SantakInference constructor

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#ifndef SANTAKCHAR_H
#define SANTAKCHAR_H

class SantakChar{
  public:
    SantakChar(std::string name, std::string desc, cv::Mat im, cv::Mat cnt);
    //name and description of character
    std::string charName;
    std::string charDesc;
    //image for display
    cv::Mat img;
    //contours for lookup, preprocessed
    cv::Mat contours;
};

#endif
