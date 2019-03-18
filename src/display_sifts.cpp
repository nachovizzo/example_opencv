// @file      display_sifts.cpp
// @author    Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @mantainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <stdio.h>
#include <opencv2/highgui/highgui.hpp>
#include "include/sifts.h"
using namespace std;
using namespace cv;

int main() {
  Mat descriptorImage;
  Mat descriptors = computeSifts("../img/lenna.png", descriptorImage);

  namedWindow("SIFT detections", WINDOW_AUTOSIZE);
  imshow("SIFT detections", descriptorImage);

  namedWindow("SIFT vector as image", WINDOW_AUTOSIZE);
  imshow("SIFT vector as image", descriptors);

  printf("Number of SIFTs: %d\n", descriptors.rows);
  printf("Size of each SIFT: %d\n", descriptors.cols);

  waitKey(0);

  return 0;
}