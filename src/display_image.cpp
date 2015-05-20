#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char const *argv[]) {
    Mat image;
    image = imread("../img/lenna.png", CV_LOAD_IMAGE_COLOR );

    if ( !image.data ) {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Window Name", WINDOW_AUTOSIZE );
    imshow("Window Name", image);

    waitKey(0);

    return 0;
    return 0;
}