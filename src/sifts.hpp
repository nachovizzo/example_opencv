// @file       sifts.h
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#ifndef SIFTS_HPP_
#define SIFTS_HPP_

#include <string>
#include <tuple>

#include <opencv2/core/mat.hpp>

std::tuple<cv::Mat, cv::Mat> ComputeSifts(const std::string& fileName);

#endif  // SIFTS_HPP_
