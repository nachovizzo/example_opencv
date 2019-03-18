# OpenCV Example #

## Prerequisites ##

You need the SIFT implementation to run this code. Check if you have a file
`nonfree.hpp` under `/usr/include/opencv2/xfeatures2d`. If it is there, you're
fine. Otherwise, follow the procedure below.

You need to install the missing non-free version of OpenCV. To do that type the
following in the terminal:

```sh
sudo add-apt-repository --yes ppa:ignaciovizzo/opencv3-nonfree
sudo apt-get update
sudo apt-get install libopencv-dev libopencv-contrib-dev
```

## How to Build ##

Build is straightforward:
```
    mkdir build/
    cd build/
    cmake ..
    make
```
