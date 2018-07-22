//abstract classs for inference packages

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "SantakChar.h"

class SantakInference {
public:
  SantakInference(cv::Ptr<cv::hdf::HDF5> h5io);
  virtual std::vector<SantakChar> search(cv::Mat query, int n) = 0;
private:
  //storing character library
  std::map<std::string, SantakChar> library;

  //creating the character library from a HDF5 files
  void _buildLibrary(cv::Ptr<cv::hdf::HDF5> h5io);


}
