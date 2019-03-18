// @file      sifts.cpp
// @author    Igor Bogoslavskyi [igor.bogoslavskyi@gmail.com]
// @mantainer Ignacio Vizzo     [ivizzo@uni-bonn.de]
//
// Copyright (c) 2018 Igor Bogoslavskyi, all rights reserved
#include "include/sifts.h"
#include <opencv2/highgui/highgui.hpp>
#include <string>
#include <vector>

using std::string;
using std::vector;

using cv::Mat;
using cv::SiftFeatureDetector;
using cv::SiftDescriptorExtractor;
using cv::KeyPoint;
using cv::DrawMatchesFlags;
using cv::Scalar;

Mat computeSifts(const string& fileName, Mat& imageWithKeypoints) {
    const Mat input = cv::imread(fileName.c_str(), CV_LOAD_IMAGE_GRAYSCALE);
    Mat descriptors;

    // detect key points
    SiftFeatureDetector detector;
    vector<KeyPoint> keypoints;
    detector.detect(input, keypoints);

    // present the keypoints on the image
    drawKeypoints(input, keypoints, imageWithKeypoints);

    // extract the SIFT descriptors
    SiftDescriptorExtractor extractor;
    extractor.compute(input, keypoints, descriptors);
    return descriptors;
}
