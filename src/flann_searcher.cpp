// Copyright Igor Bogoslavskyi, year 2015.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using std::cout;
using std::endl;
using cv::Mat;
using cv::Scalar;
using cv::DataType;

int main(int argc, char const *argv[]) {
    // init some parameters
    int rowsNum = 1;
    int colsNum = 10;
    Mat data;

    // fill the dummy data
    int step = 9;
    int maxDataIdx = 100;
    for (int i = 0; i < maxDataIdx; i += step) {
        Mat someVector(rowsNum, colsNum,
                       DataType<float>::type, static_cast<float>(i));
        data.push_back(someVector);
    }
    cout << "whole data is \n" << data << endl << endl;

    // create a kdtree for searching the data
    cv::flann::KDTreeIndexParams indexParams(4);
    cv::flann::Index kdtree(data, indexParams);

    // create a query vector
    int queryIdx = 50;
    Mat query(rowsNum, colsNum,
              DataType<float>::type, static_cast<float>(queryIdx));
    cout << "query vector is \n" << query << endl << endl;

    // search the nearest vector to it
    int k = 1;
    Mat nearestVectorIdx(1, k, DataType<int>::type);
    Mat nearestVectorDist(1, k, DataType<float>::type);
    kdtree.knnSearch(query, nearestVectorIdx, nearestVectorDist, k);

    int closestIdx = nearestVectorIdx.at<int>(0, 0);
    float closestDist = nearestVectorDist.at<float>(0, 0);
    cout << "Closest idx = " << closestIdx
         << ", with distance = " << closestDist << endl;
    cout << "closest vector is data[" << closestIdx << "]\n"
         << data.row(closestIdx) << endl;

    return 0;
}