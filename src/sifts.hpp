// @file       sifts.h
// @author     Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @maintainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#pragma once
#include <string>

#include <opencv2/core/core.hpp>

cv::Mat computeSifts(const std::string& fileName, cv::Mat& imageWithKeypoints);
