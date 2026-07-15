cmake_minimum_required(VERSION 3.14)
project(GithubProfileGenerator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(json
    GIT_REPOSITORY  https://github.com/nlohmann/json.git
    GIT_TAG         55f93686c01528224f448c19128836e7df245f72
)

FetchContent_Declare(cpr
    GIT_REPOSITORY  https://github.com/libcpr/cpr.git
    GIT_TAG         f091b2c061b307ee89b164c39976fc9202a1c79d
)

set(CPR_USE_SYSTEM_CURL OFF CACHE BOOL "" FORCE)
set(CPR_CURL_USE_LIBPSL OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(json cpr)

add_executable(generate_profile
    src/main.cpp
    src/svg_renderer.cpp
    src/ascii_gen.cpp
)

target_include_directories(generate_profile PRIVATE include)

target_link_libraries(generate_profile PRIVATE 
    nlohmann_json::nlohmann_json
    cpr::cpr
)
