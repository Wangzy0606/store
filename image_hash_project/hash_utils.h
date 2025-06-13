#ifndef HASH_UTILS_H
#define HASH_UTILS_H

#include <opencv2/opencv.hpp>
#include <string>

std::string computeImageSHA256(const cv::Mat& image);

#endif