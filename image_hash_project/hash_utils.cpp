#include "hash_utils.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string computeImageSHA256(const cv::Mat& image) {
    std::string hashStr;
    if (image.empty()) return hashStr;

    std::vector<uchar> buf;
    cv::imencode(".png", image, buf);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(buf.data(), buf.size(), hash);

    std::ostringstream oss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];

    return oss.str();
}