cmake_minimum_required(VERSION 3.10)
project(SimpleBlockchain VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Add include directories
include_directories(
    include
    ${OPENSSL_INCLUDE_DIR}
)

# Add source files
add_executable(blockchain 
    src/main.cpp 
    src/block.cpp 
    src/blockchain.cpp
)

# Link OpenSSL libraries
target_link_libraries(blockchain 
    ${OPENSSL_LIBRARIES}
)

# Add compiler warnings
if(MSVC)
    target_compile_options(blockchain PRIVATE /W4)
else()
    target_compile_options(blockchain PRIVATE -Wall -Wextra -Wpedantic)
endif()