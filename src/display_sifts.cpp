// @file       display_sifts.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "sifts.hpp"

int main() {
  cv::Mat descriptor_image;
  cv::Mat descriptors = ComputeSifts("../../img/lenna.png", descriptor_image);

  cv::namedWindow("SIFT detections", cv::WINDOW_AUTOSIZE);
  imshow("SIFT detections", descriptor_image);

  cv::namedWindow("SIFT vector as image", cv::WINDOW_AUTOSIZE);
  imshow("SIFT vector as image", descriptors);

  std::cout << "Number of SIFTs: " << descriptors.rows << "\n"
            << "Size of each SIFT: " << descriptors.cols << "\n";

  cv::waitKey(0);

  return 0;
}
