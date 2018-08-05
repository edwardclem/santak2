//abstract classs for inference packages



#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/hdf.hpp>
#include "SantakChar.h"
#include <string>
#include <nlohmann/json.hpp>


#ifndef SANTAKINFERENCE_H
#define SANTAKINFERENCE_H

class SantakInference {
public:
  SantakInference(std::string data_prefix);
  //reimplemented in subclasses
  virtual std::vector<SantakChar> search(cv::Mat query, int n) = 0;
private:
  //storing character library
  std::map<std::string, SantakChar> library;

  //creating the character library from a HDF and JSON files
  void _buildLibrary(nlohmann::json j, std::string h5file);


};

#endif
