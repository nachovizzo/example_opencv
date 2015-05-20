// Copyright Igor Bogoslavskyi, year 2015.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#include "include/sifts.h"
#include <stdio.h>
using namespace std;
using namespace cv;

int main() {
    Mat descriptorImage;
    Mat descriptors = computeSifts("../img/lenna.png", descriptorImage);

    namedWindow("SIFT detections", WINDOW_AUTOSIZE );
    imshow("SIFT detections", descriptorImage);

    namedWindow("SIFT vector as image", WINDOW_AUTOSIZE );
    imshow("SIFT vector as image", descriptors);

    printf("Number of SIFTs: %d\n", descriptors.rows);
    printf("Size of each SIFT: %d\n", descriptors.cols);

    waitKey(0);

    return 0;
}