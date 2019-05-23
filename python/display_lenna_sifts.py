#!/usr/bin/env python3
# -*- coding: utf-8 -*-
# @file      display_lenna_sifts.py
# @author    Ignacio Vizzo     [ivizzo@uni-bonn.de]
#
# Copyright (c) 2019 Ignacio Vizzo, all rights reserved
#
# This is a python example on how to use SIFT implementation from OpenCV. You
# should not use this for your project. It's just a demo to show you you could
# do some prototyping with Python(if you know python). Of course all the
# algorithms used in this example are implemented in C++, the functions we use
# here are just simple wrappers to the C++ implementations

import cv2

if __name__ == "__main__":
    # Read the image from file
    image = cv2.imread("../img/lenna.png", cv2.IMREAD_GRAYSCALE)

    # Create SIFT detector and obtain the keypoints and descriptors
    detector = cv2.xfeatures2d.SIFT_create()
    keypoints, descriptors = detector.detectAndCompute(image, None)

    # Show the keypoints on top of the image
    img = cv2.drawKeypoints(image, keypoints, None)
    cv2.imshow("Image", img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
