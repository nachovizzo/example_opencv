add_executable(display_image display_image.cpp)
target_link_libraries(display_image ${OpenCV_LIBS})

add_executable(display_sifts display_sifts.cpp)
target_link_libraries(display_sifts sift_compute_lib ${OpenCV_LIBS})

add_executable(flann_searcher flann_searcher.cpp)
target_link_libraries(flann_searcher ${OpenCV_LIBS})
