// @file       display_image.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved

#include <cstdlib>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

int main() {
  auto image = cv::imread("../../img/lenna.png", cv::IMREAD_GRAYSCALE);
  if (image.empty()) {
    std::cerr << "No image data \n";
    return EXIT_FAILURE;
  }
  cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
  cv::imshow("Window Name", image);

  cv::waitKey(0);

  return 0;
}
