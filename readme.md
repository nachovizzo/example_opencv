# OpenCV Example #

## Prerequisites ##
You need the SIFT implementation to run this code. Check if you have a folder `nonfree` under `/usr/include/opencv2/`. If it is there, you're fine. Otherwise, follow the procedure below.

You need to install the missing non-free version of OpenCV. To do that type the following in the terminal:
```
    sudo add-apt-repository --yes ppa:xqms/opencv-nonfree
    sudo apt-get update
    sudo apt-get install libopencv-nonfree-dev
```

## How to Build ##
Build is straightforward:
```
    mkdir build/
    cd build/
    cmake ..
    make
```
