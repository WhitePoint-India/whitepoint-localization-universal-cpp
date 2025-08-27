cmake_minimum_required(VERSION 3.11)
project(MyApplication VERSION 1.0.0 LANGUAGES CXX)

# Include FetchContent module
include(FetchContent)

# Option 1: Fetch localization library from GitHub
# FetchContent_Declare(
#     localization
#     GIT_REPOSITORY https://github.com/your-username/whitepoint-localization-universal-cpp.git
#     GIT_TAG main # or specify a specific tag/commit
# )

# Option 2: Fetch localization library from local path (useful for development)
FetchContent_Declare(
    localization
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Make the library available
FetchContent_MakeAvailable(localization)

# Create your executable
add_executable(example src/main.cpp)

# Link the localization library
target_link_libraries(example PRIVATE localization)

# Set C++ standard (requires C++20 for std::format)
target_compile_features(example PRIVATE cxx_std_20)