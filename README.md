# OpenCV 4 Example

## Prerequisites

You need to install some dependencies on your system before installing `OpenCV4`

```sh
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev
```

## Install OpenCV4 from source

This example suppose that you have installed **`Ubuntu 18.04`** on your dev
machine. You need the SIFT implementation to run this code...

You need to install the missing non-free version of OpenCV4. To do that type the
following in the terminal:

```sh
# First cd into where you want to put the Opencv library, e.g ~/dev/libs/
mkdir -p ~/dev/libs && cd ~/dev/libs/
git clone https://github.com/opencv/opencv.git -b 4.3.0
git clone https://github.com/opencv/opencv_contrib.git -b 4.3.0
mkdir opencv/build && cd opencv/build
cmake -DOPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules ..
make -j$(nproc --all) && sudo make install
```

## How to Build the examples on this repository

Build is straightforward:

```sh
mkdir build/
cd build/
cmake ..
make
```
