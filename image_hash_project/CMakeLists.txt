cmake_minimum_required(VERSION 3.30)
project(ImageHashCompare)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)

add_executable(ImageHashCompare main.cpp hash_utils.cpp)

target_include_directories(ImageHashCompare PRIVATE ${OpenCV_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})
target_link_libraries(ImageHashCompare PRIVATE ${OpenCV_LIBS} OpenSSL::Crypto)