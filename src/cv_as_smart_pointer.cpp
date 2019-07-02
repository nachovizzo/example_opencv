// @file      cv_as_smart_pointer.cpp
// @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2019 Ignacio Vizzo, all rights reserved

#include <chrono>
#include <iostream>
#include <opencv2/core.hpp>

using std::cout;
using std::endl;

#define START_CLOCK() start = std::chrono::system_clock::now();
#define STOP_CLOCK()                                                      \
  end = std::chrono::system_clock::now();                                 \
  elapsed =                                                               \
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start); \
  cout << "Time Elapsed " << elapsed.count() << " milliseconds" << endl << endl;

#define INIT_UGLY_TIME_FACILITIES()              \
  auto start = std::chrono::system_clock::now(); \
  auto end = std::chrono::system_clock::now();   \
  auto elapsed =                                 \
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

// The example matrix should allocate 8 bytes(one double value) in the heap
// memory:
//  cv::Mat1d mat(1, 1);  // Or: Mat mat(2, 4, CV_64FC1);
// Of course if we use int or something else this "8 bytes" will change.
// We want to consume much more memory instead, something in the MiB order:
// 8 bytes * cols * rows = 1 GiB -> rows = cols = sqrt(1e+9/8) ~= 11180
const int rows = 11180;
const int cols = 11180;
const double low = -500.0;
const double high = +500.0;

template <class T>
T DoNothing(T mat) {
  puts(__PRETTY_FUNCTION__);
  T mat_maybe_copy = mat;
  return mat_maybe_copy;
}

template <class T>
T DoNothingByRef(const T& mat) {
  puts(__PRETTY_FUNCTION__);
  T mat_maybe_copy = mat;
  return mat_maybe_copy;
}

cv::Mat GetDummyData(void) {
  cv::Mat1d mat(rows, cols);
  cv::randu(mat, cv::Scalar(low), cv::Scalar(high));
  return mat;
}

int main() {
  cv::Mat1d mat(rows, cols);
  // time facilities to benchmark time... this is ugly
  INIT_UGLY_TIME_FACILITIES();

  START_CLOCK();
  cv::randu(mat, cv::Scalar(low), cv::Scalar(high));
  STOP_CLOCK();

  START_CLOCK();
  cout << "About to get a cv::Mat from somewhere else, copying data?" << endl
       << "This should take roughly the same as before, not the double" << endl;
  auto foo1 = GetDummyData();
  STOP_CLOCK();

  START_CLOCK();
  cout << "About to copy a cv::Mat from somewhere else" << endl
       << "This should take roughly the the double as before" << endl;
  auto foo2 = GetDummyData().clone();
  STOP_CLOCK();

  START_CLOCK();
  auto foo3 = DoNothing(mat);
  STOP_CLOCK();

  START_CLOCK();
  auto foo4 = DoNothingByRef(mat);
  STOP_CLOCK();

  // Wait for user.
  cout << "Press enter to exit " << endl;
  std::cin.get();

  return 0;
}
