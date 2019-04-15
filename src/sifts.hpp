// @file       sifts.h
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#ifndef SIFTS_HPP_
#define SIFTS_HPP_

#include <string>

#include <opencv2/core/core.hpp>

cv::Mat ComputeSifts(const std::string& fileName, cv::Mat& imageWithKeypoints);

#endif  // SIFTS_HPP_
