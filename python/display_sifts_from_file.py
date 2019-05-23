#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @file      display_sifts_from_file.py
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2019 Ignacio Vizzo, all rights reserved
"""
This is a python example on how to use SIFT implementation from OpenCV. You
should not use this for your project. It's just a demo to show you you could
do some prototyping with Python(if you know python). Of course all the
algorithms used in this example are implemented in C++, the functions we use
here are just simple wrappers to the C++ implementations

Example of usage:

    $ ./display_sifts_from_file.py -f ../img/lenna.png
    $ ./display_sifts_from_file.py -f data1/imageCompressedCam0_0000060.png
"""

import argparse

import cv2

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--filename', '-f',
                        required=True,
                        help='Path to image file',
                        type=str)
    args = parser.parse_args()

    # Read the image from file
    image = cv2.imread(args.filename, cv2.IMREAD_GRAYSCALE)

    # Create SIFT detector and obtain the keypoints and descriptors
    detector = cv2.xfeatures2d.SIFT_create()
    keypoints, descriptors = detector.detectAndCompute(image, None)

    # Show the keypoints on top of the image
    img = cv2.drawKeypoints(image, keypoints, None)
    cv2.imshow("Image", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
