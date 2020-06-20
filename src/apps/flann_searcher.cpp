// @file       flann_searcher.cpp
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/flann.hpp>

using cv::DataType;
using cv::Mat;
using std::cout;
using std::endl;

int main() {
  // init some parameters
  int rows_num = 1;
  int cols_num = 10;
  Mat data;

  // fill the dummy data
  int step = 9;
  int max_data_idx = 100;
  for (int i = 0; i < max_data_idx; i += step) {
    Mat vec(rows_num, cols_num, DataType<float>::type, static_cast<float>(i));
    data.push_back(vec);
  }
  cout << "whole data is \n" << data << endl << endl;

  // create a kdtree for searching the data
  cvflann::KDTreeIndexParams index_params;
  cv::flann::GenericIndex<cvflann::L2<float>> kdtree(data, index_params);

  // create a query vector
  int query_idx = 50;
  Mat query(rows_num, cols_num, DataType<float>::type,
            static_cast<float>(query_idx));
  cout << "query vector is \n" << query << endl << endl;

  // search the nearest vector to it
  int knn = 2;
  std::vector<int> indices(knn);
  std::vector<float> distances(knn);
  cvflann::SearchParams search_params;
  kdtree.knnSearch(query, indices, distances, knn, search_params);

  int closest_idx = indices[0];
  float closest_dist = distances[0];
  cout << "Closest idx = " << closest_idx
       << ", with distance = " << closest_dist << endl;
  cout << "Closest vector is data[" << closest_idx << "]\n"
       << data.row(closest_idx) << endl
       << endl;

  int second_closest_idx = indices[1];
  float second_closest_dist = distances[1];
  cout << "Second closest idx = " << second_closest_idx
       << ", with distance = " << second_closest_dist << endl;
  cout << "Second closest vector is data[" << second_closest_idx << "]\n"
       << data.row(second_closest_idx) << endl;

  return 0;
}
