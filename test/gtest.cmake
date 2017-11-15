include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    CMAKE_ARGS -Dgtest_force_shared_crt=ON
               -DBUILD_GTEST=ON
    PREFIX     "${PROJECT_SOURCE_DIR}/third_parts/googletest"
#Disable install stop
    INSTALL_COMMAND ""
)
# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/googletest/include)
message(STATUS "the GTEST_INCLUD_DIRS: " "${GTEST_INCLUDE_DIRS}")

# Specify MainTest's link librares
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR ${binary_dir}/googlemock/gtest)
message(STATUS "the GTEST_LIBS_DIR: " "${GTEST_LIBS_DIR}")
