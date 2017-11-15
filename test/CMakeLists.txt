#https://www.slothparadise.com/google-testing-example-and-cmake-integration/
include(gtest.cmake)
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/compass)

file(GLOB_RECURSE TEST_SRC_FILES RELATIVE ${PROJECT_SOURCE_DIR}/test *.cc)
message(STATUS "the TEST_SRC_FILES: " "${TEST_SRC_FILES}")
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)
add_dependencies(${PROJECT_TEST_NAME} ${PROJECT_NAME})
target_link_libraries(${PROJECT_TEST_NAME}
    pthread
    ${LIBRARY_OUTPUT_PATH}/libcompass_base.a
    ${GTEST_LIBS_DIR}/libgtest.a
    ${GTEST_LIBS_DIR}/libgtest_main.a
)
add_test(NAME ${PROJECT_TEST_NAME} COMMAND ${PROJECT_TEST_NAME})
#add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} DEPENDS ${PROJECT_TEST_NAME})
add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose)
