cmake_minimum_required(VERSION 3.15)
project(IGenericDataProvider)

set(CMAKE_CXX_STANDARD 11)

set(IGenericDataProvider_VERSION_MAJOR 0)
set(IGenericDataProvider_VERSION_MINOR 0)
set(IGenericDataProvider_VERSION_PATCH 1)

add_library(IGenericDataProvider INTERFACE)
target_compile_features(IGenericDataProvider INTERFACE cxx_std_11)
target_include_directories(IGenericDataProvider INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
                           $<INSTALL_INTERFACE:include>)

install(TARGETS IGenericDataProvider EXPORT IGenericDataProviderTargets)
install(FILES include/IGenericDataProvider/if_generic_data_provider.h DESTINATION include/IGenericDataProvider)
install(EXPORT IGenericDataProviderTargets
        FILE IGenericDataProvider.cmake
        DESTINATION lib/cmake/IGenericDataProvider)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/IGenericDataProviderConfig.cmake
        DESTINATION lib/cmake/IGenericDataProvider)
install(EXPORT IGenericDataProviderTargets
        FILE IGenericDataProviderTargets.cmake
        DESTINATION lib/cmake/IGenericDataProvider)

include(CMakePackageConfigHelpers)
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
        "${CMAKE_CURRENT_BINARY_DIR}/IGenericDataProviderConfig.cmake"
        INSTALL_DESTINATION "lib/cmake/IGenericDataProvider"
        NO_SET_AND_CHECK_MACRO
        NO_CHECK_REQUIRED_COMPONENTS_MACRO)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/IGenericDataProviderConfigVersion.cmake"
        VERSION "${IGenericDataProvider_VERSION_MAJOR}.${IGenericDataProvider_VERSION_MINOR}"
        COMPATIBILITY AnyNewerVersion)

export(EXPORT IGenericDataProviderTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/IGenericDataProviderTargets.cmake")