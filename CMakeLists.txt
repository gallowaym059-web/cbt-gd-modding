cmake_minimum_required(VERSION 3.21)
project(CBTMod VERSION 1.0.0 LANGUAGES CXX)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
    src/hooks/game_loop.cpp
    src/features/click_before_tick.cpp
    src/features/tps_bypass.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Link Geode
target_link_libraries(${PROJECT_NAME} geode-sdk)

# Platform-specific setup
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".dll"
        PREFIX ""
    )
elseif(APPLE)
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".dylib"
        PREFIX ""
    )
else()
    set_target_properties(${PROJECT_NAME} PROPERTIES
        SUFFIX ".so"
        PREFIX ""
    )
endif()
