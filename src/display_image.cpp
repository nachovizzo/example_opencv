// @file      display_image.cpp
// @author    Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @mantainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char const *argv[]) {
  Mat image;
  image = imread("../img/lenna.png", CV_LOAD_IMAGE_GRAYSCALE);

  if (!image.data) {
    printf("No image data \n");
    return -1;
  }
  namedWindow("Window Name", WINDOW_AUTOSIZE);
  imshow("Window Name", image);

  waitKey(0);

  return 0;
}