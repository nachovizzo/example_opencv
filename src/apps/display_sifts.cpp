// @file       display_sifts.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "sift_compute/sifts.hpp"

int main() {
  auto [descriptors, image_with_kp] = ComputeSifts("../../img/lenna.png");

  cv::namedWindow("SIFT detections", cv::WINDOW_AUTOSIZE);
  cv::imshow("SIFT detections", image_with_kp);

  cv::namedWindow("SIFT vector as image", cv::WINDOW_AUTOSIZE);
  imshow("SIFT vector as image", descriptors);

  std::cout << "Number of SIFTs: " << descriptors.rows << "\n"
            << "Size of each SIFT: " << descriptors.cols << "\n";

  cv::waitKey(0);

  return 0;
}
