#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include "hash_utils.h"

int main() {
    std::string filename;
    std::cout << "Enter image path: ";
    std::cin >> filename;

    cv::Mat image = cv::imread(filename);
    if (image.empty()) {
        std::cerr << "Failed to load image.\n";
        return 1;
    }

    std::string hash1 = computeImageSHA256(image);
    std::cout << "Original SHA256: " << hash1 << "\n";

    image.at<cv::Vec3b>(0, 0)[0] ^= 1;

    std::string hash2 = computeImageSHA256(image);
    std::cout << "Modified SHA256: " << hash2 << "\n";

    bool same = (hash1 == hash2);
    std::cout << "Hashes are " << (same ? "equal" : "different") << ".\n";

    std::ofstream out("hash_result.txt");
    out << "Original SHA256: " << hash1 << "\n";
    out << "Modified SHA256: " << hash2 << "\n";
    out << "Hashes are " << (same ? "equal" : "different") << ".\n";
    out.close();

    return 0;
}