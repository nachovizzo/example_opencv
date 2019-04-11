// @file       flann_searcher.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>

using cv::DataType;
using cv::Mat;
using cv::Scalar;
using std::cout;
using std::endl;

int main() {
  // init some parameters
  int rowsNum = 1;
  int colsNum = 10;
  Mat data;

  // fill the dummy data
  int step = 9;
  int maxDataIdx = 100;
  for (int i = 0; i < maxDataIdx; i += step) {
    Mat vec(rowsNum, colsNum, DataType<float>::type, static_cast<float>(i));
    data.push_back(vec);
  }
  cout << "whole data is \n" << data << endl << endl;

  // create a kdtree for searching the data
  cv::flann::KDTreeIndexParams indexParams(4);
  cv::flann::Index kdtree(data, indexParams);

  // create a query vector
  int queryIdx = 50;
  Mat query(rowsNum, colsNum, DataType<float>::type,
            static_cast<float>(queryIdx));
  cout << "query vector is \n" << query << endl << endl;

  // search the nearest vector to it
  int k = 2;
  Mat nearestVectorIdx(1, k, DataType<int>::type);
  Mat nearestVectorDist(1, k, DataType<float>::type);
  kdtree.knnSearch(query, nearestVectorIdx, nearestVectorDist, k);

  int closestIdx = nearestVectorIdx.at<int>(0, 0);
  float closestDist = nearestVectorDist.at<float>(0, 0);
  cout << "Closest idx = " << closestIdx << ", with distance = " << closestDist
       << endl;
  cout << "Closest vector is data[" << closestIdx << "]\n"
       << data.row(closestIdx) << endl
       << endl;

  int secondClosestIdx = nearestVectorIdx.at<int>(0, 1);
  float secondClosestDist = nearestVectorDist.at<float>(0, 1);
  cout << "Second closest idx = " << secondClosestIdx
       << ", with distance = " << secondClosestDist << endl;
  cout << "Second closest vector is data[" << secondClosestIdx << "]\n"
       << data.row(secondClosestIdx) << endl;

  return 0;
}
