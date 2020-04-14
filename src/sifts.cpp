// @file       sifts.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved

#include "sifts.hpp"

#include <string>
#include <tuple>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

using std::string;
using std::vector;

using cv::xfeatures2d::SiftDescriptorExtractor;
using cv::xfeatures2d::SiftFeatureDetector;

std::tuple<cv::Mat, cv::Mat> ComputeSifts(const string& fileName) {
  const cv::Mat kInput = cv::imread(fileName, cv::IMREAD_GRAYSCALE);

  // detect key points
  auto detector = SiftFeatureDetector::create();
  vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);

  // present the keypoints on the image
  cv::Mat image_with_keypoints;
  drawKeypoints(kInput, keypoints, image_with_keypoints);

  // extract the SIFT descriptors
  cv::Mat descriptors;
  auto extractor = SiftDescriptorExtractor::create();
  extractor->compute(kInput, keypoints, descriptors);

  return std::make_tuple(descriptors, image_with_keypoints);
}
