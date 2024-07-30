cmake_minimum_required(VERSION 3.10.2)
project(walletapi)

# Set the directory containing the prebuilt libraries based on the ABI
set(ZANO_NATIVE_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI}/lib")
set(ZANO_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/include")
set(HEADERS_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}")

# OpenSSL
set(OPENSSL_NATIVE_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/zano_native_lib/_libs_android/openssl/${ANDROID_ABI}/lib")
set(OPENSSL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/zano_native_lib/_libs_android/openssl/include")

# Boost
set(BOOST_NATIVE_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/zano_native_lib/_libs_android/boost/${ANDROID_ABI}/lib")

# Include the headers
include_directories(${ZANO_INCLUDE_DIR})
include_directories(${HEADERS_INCLUDE})
include_directories(${OPENSSL_INCLUDE_DIR})

# Declare the imported static libraries
add_library(common STATIC IMPORTED)
add_library(crypto STATIC IMPORTED)
add_library(currency_core STATIC IMPORTED)
add_library(wallet STATIC IMPORTED)
add_library(z STATIC IMPORTED)

add_library(openssl_crypto STATIC IMPORTED)
add_library(openssl_ssl STATIC IMPORTED)

add_library(boost_atomic STATIC IMPORTED)
add_library(libboost_chrono STATIC IMPORTED)
add_library(libboost_date_time STATIC IMPORTED)
add_library(libboost_filesystem STATIC IMPORTED)
add_library(libboost_program_options STATIC IMPORTED)
add_library(libboost_regex STATIC IMPORTED)
add_library(libboost_serialization STATIC IMPORTED)
add_library(libboost_system STATIC IMPORTED)
add_library(libboost_thread STATIC IMPORTED)
add_library(libboost_timer STATIC IMPORTED)
add_library(libboost_wserialization STATIC IMPORTED)

# Set the properties for each imported library
set_target_properties(common PROPERTIES IMPORTED_LOCATION "${ZANO_NATIVE_LIB_DIR}/libcommon.a")
set_target_properties(crypto PROPERTIES IMPORTED_LOCATION "${ZANO_NATIVE_LIB_DIR}/libcrypto.a")
set_target_properties(currency_core PROPERTIES IMPORTED_LOCATION "${ZANO_NATIVE_LIB_DIR}/libcurrency_core.a")
set_target_properties(wallet PROPERTIES IMPORTED_LOCATION "${ZANO_NATIVE_LIB_DIR}/libwallet.a")
set_target_properties(z PROPERTIES IMPORTED_LOCATION "${ZANO_NATIVE_LIB_DIR}/libz.a")

set_target_properties(openssl_crypto PROPERTIES IMPORTED_LOCATION "${OPENSSL_NATIVE_LIB_DIR}/libcrypto.a")
set_target_properties(openssl_ssl PROPERTIES IMPORTED_LOCATION "${OPENSSL_NATIVE_LIB_DIR}/libssl.a")

set_target_properties(boost_atomic PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_atomic.a")
set_target_properties(libboost_chrono PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_chrono.a")
set_target_properties(libboost_date_time PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_date_time.a")
set_target_properties(libboost_filesystem PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_filesystem.a")
set_target_properties(libboost_program_options PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_program_options.a")
set_target_properties(libboost_regex PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_regex.a")
set_target_properties(libboost_serialization PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_serialization.a")
set_target_properties(libboost_system PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_system.a")
set_target_properties(libboost_thread PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_thread.a")
set_target_properties(libboost_timer PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_timer.a")
set_target_properties(libboost_wserialization PROPERTIES IMPORTED_LOCATION "${BOOST_NATIVE_LIB_DIR}/libboost_wserialization.a")

# Create the shared library for JNI
add_library(walletapi SHARED PlainWalletApi.cpp)

# Link the native libraries
target_link_libraries(
        walletapi
        common
        crypto
        currency_core
        wallet
        z
        openssl_ssl
        openssl_crypto
        boost_atomic
        libboost_chrono
        libboost_date_time
        libboost_filesystem
        libboost_program_options
        libboost_regex
        libboost_serialization
        libboost_system
        libboost_thread
        libboost_timer
        libboost_wserialization
        log
        atomic
        m
)
