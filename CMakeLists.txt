# Localization library CMakeLists.txt
cmake_minimum_required(VERSION 3.11)

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
    localization.cpp
    locale.cpp
)

# Set include directories for this library
target_include_directories(localization PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# Link nlohmann_json to localization
target_link_libraries(localization PUBLIC nlohmann_json::nlohmann_json)