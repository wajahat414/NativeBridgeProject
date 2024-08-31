cmake_minimum_required(VERSION 3.22.1)

project("nativebridgeproject")

set(distribution_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../distribution)

# Add libraries
add_library(curl STATIC IMPORTED)
set_target_properties(curl PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/curl/${ANDROID_ABI}/lib/libcurl.a)

add_library(openssl STATIC IMPORTED)
set_target_properties(openssl PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/openssl/${ANDROID_ABI}/lib/libssl.a)

add_library(lib_crypto STATIC IMPORTED)
set_target_properties(lib_crypto PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/openssl/${ANDROID_ABI}/lib/libcrypto.a)

add_library(lib_z STATIC IMPORTED)
set_target_properties(lib_z PROPERTIES IMPORTED_LOCATION
        ${distribution_DIR}/zlib/${ANDROID_ABI}/lib/libz.a)

# Add the main shared library target
add_library(${CMAKE_PROJECT_NAME} SHARED
        native-lib.cpp)

# Include directories
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        ${distribution_DIR}/openssl/${ANDROID_ABI}/include
        ${distribution_DIR}/zlib/${ANDROID_ABI}/include
        ${distribution_DIR}/curl/${ANDROID_ABI}/include)

# Child and Parent Libraries
add_library(
        child_lib
        SHARED
        child_lib/child_library.cpp
)

add_library(
        parent_lib
        SHARED
        parent_lib/parent_library.cpp
)

# Linking libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
        android
        openssl
        lib_crypto
        lib_z
        curl
        dl
        log)
