//implementation of shared SantakInference methods


#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <nlohmann/json.hpp>
#include <string>
#include "SantakChar.h"
#include "SantakInference.h"
#include <assert.h>

using json = nlohmann::json;

SantakInference::SantakInference(std::string data_prefix){
  /*
  Builds the SantakInference library from the provided data prefix.
  */

  //creating JSON and HDF5 file names from provided prefix
  std::string jfile = data_prefix + ".json";
  std::string h5file = data_prefix + ".h5";
  //Loads JSON from file.
  std::cout << "Loading JSON data from " <<  jfile << std::endl;
  std::ifstream stream(jfile);
  json j;
  stream >> j;

  this->_buildLibrary(j, h5file);
}

void SantakInference::_buildLibrary(json j, std::string h5file){
  /*
  Constructs a map from the provided hdf5 and JSON files.
  Map keys: integers containing unicode code points
  Map values: SantakChar instances containing character info
  */


  //load hdf5 file from name
  cv::Ptr<cv::hdf::HDF5> h5io = cv::hdf::open(h5file);

  //check that headers exist

  assert(h5io->hlexists("imgs"));
  assert(h5io->hlexists("contours"));

  //populate map
  for (json::iterator it = j.begin(); it != j.end(); ++it) {

    //load image
    cv::Mat img;
    assert(h5io->hlexists("imgs/" + it.key()));
    h5io->dsread(img, "imgs/" + it.key());

    //load contours
    cv::Mat contour;
    assert(h5io->hlexists("contours/" + it.key()));
    h5io->dsread(img, "contours/" + it.key());

    //create character
    SantakChar character(it.key(), it.value(), img, contour);

    //populate map
    this->library[it.key()] =  character;

  }

}
