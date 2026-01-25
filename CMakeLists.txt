cmake_minimum_required(VERSION 4.0)

# Allow standalone build or as subdirectory
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    project(logger VERSION 1.0.0 LANGUAGES CXX)
    set(CMAKE_CXX_STANDARD 23)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# Library sources
set(LOGGER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/logging.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logger.cpp
)

# Library headers
set(LOGGER_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/logging.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logger.h
)

# Create the logger library
add_library(logger STATIC ${LOGGER_SOURCES} ${LOGGER_HEADERS})

# Set include directories for the library
target_include_directories(logger
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

# Find dependencies
find_package(spdlog REQUIRED)
find_package(fmt CONFIG REQUIRED)

# Link dependencies
target_link_libraries(logger PUBLIC spdlog::spdlog fmt::fmt)
