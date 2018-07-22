#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

SantakChar::SantakChar(std::string name, std::string desc, cv::Mat im, cv::Mat cnt){
      //assign properties to character class
      //TODO: check memory allocation issues here

      charName = name;
      charDesc = desc;
      img = im;
      contours = cnt;

}
