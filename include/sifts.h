// @file      sifts.h
// @author    Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @mantainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#pragma once

#include <opencv2/core/core.hpp>
#include <string>

cv::Mat computeSifts(const std::string& fileName, cv::Mat& imageWithKeypoints);
