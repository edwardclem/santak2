//implementing shape context lookup using CPU OpenCV function, as baseline

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/hdf.hpp>
#include "SantakInference.h"
#include <opencv2/shape.hpp>

#ifndef SANTAKINFERENCEOPENCV_H
#define SANTAKINFERENCEOPENCV_H

class SantakInferenceOpenCV: public SantakInference {
public:
  SantakInferenceOpenCV(std::string data_prefix);
  //search function
  std::vector<SantakChar> search(cv::Mat query, int n);
  //distance extractor
  cv::Ptr <cv::ShapeContextDistanceExtractor> extractor;


};

#endif
