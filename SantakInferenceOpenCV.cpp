#include "SantakInferenceOpenCV.h"
#include "SantakInference.h"
#include <cstddef>
#include <opencv2/shape.hpp>


SantakInferenceOpenCV::SantakInferenceOpenCV(std::string data_prefix) :
  SantakInference(data_prefix){
    std::cout << "Constructing Inference Object" << std::endl;
    this->extractor = cv::createShapeContextDistanceExtractor()
  }

std::vector<SantakChar> SantakInferenceOpenCV::search(cv::Mat query, int n){

    std::vector<SantakChar> results;

    float dists[this->library.size()];

    

    return results;
  }
