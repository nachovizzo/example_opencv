// Copyright Igor Bogoslavskyi, year 2015.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

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

    // detect SIFT features
    SiftFeatureDetector detector;
    vector<KeyPoint> keypoints;
    detector.detect(input, keypoints);

    // present the keypoints on the image
    drawKeypoints(input, keypoints, imageWithKeypoints,
                   Scalar::all(-1), DrawMatchesFlags::DEFAULT);

    // extract the descriptors
    SiftDescriptorExtractor extractor;
    extractor.compute(input, keypoints, descriptors);
    return descriptors;
}
