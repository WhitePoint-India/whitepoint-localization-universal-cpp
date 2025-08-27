# Localization library CMakeLists.txt
cmake_minimum_required(VERSION 3.11)
project(localization VERSION 1.0.0 LANGUAGES CXX)

# Include FetchContent module
include(FetchContent)

# Fetch JSON for Modern C++
FetchContent_Declare(json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(json)

# Create localization library
add_library(localization STATIC
    src/localization.cpp
    src/locale.cpp
)

# Set include directories for this library
# BUILD_INTERFACE: Used when building the library
# INSTALL_INTERFACE: Used when the library is installed
target_include_directories(localization PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link nlohmann_json to localization
target_link_libraries(localization PUBLIC nlohmann_json::nlohmann_json)

# Set C++ standard (requires C++20 for std::format)
target_compile_features(localization PUBLIC cxx_std_20)