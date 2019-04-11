// @file       display_image.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <iostream>

#include <opencv2/opencv.hpp>

int main() {
  cv::Mat image;
  image = cv::imread("../../img/lenna.png", CV_LOAD_IMAGE_GRAYSCALE);

  if (image.data == nullptr) {
    std::cerr << "No image data \n";
    return -1;
  }
  cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
  imshow("Window Name", image);

  cv::waitKey(0);

  return 0;
}
