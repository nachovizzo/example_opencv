// @file       sifts.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include "sifts.hpp"

#include <memory>
#include <string>
#include <vector>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>

using std::string;
using std::vector;

using cv::xfeatures2d::SiftDescriptorExtractor;
using cv::xfeatures2d::SiftFeatureDetector;

cv::Mat ComputeSifts(const string& fileName,
                     const std::unique_ptr<cv::Mat>& imageWithKeypoints) {
  const cv::Mat kInput = cv::imread(fileName.c_str(), CV_LOAD_IMAGE_GRAYSCALE);
  cv::Mat descriptors;

  // detect key points
  auto detector = SiftFeatureDetector::create();
  vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);

  // present the keypoints on the image
  drawKeypoints(kInput, keypoints, *imageWithKeypoints);

  // extract the SIFT descriptors
  auto extractor = SiftDescriptorExtractor::create();
  extractor->compute(kInput, keypoints, descriptors);
  return descriptors;
}
