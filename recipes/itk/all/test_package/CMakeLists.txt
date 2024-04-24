cmake_minimum_required(VERSION 3.15)

project(test_package CXX)

find_package(ITK REQUIRED)

add_executable(${PROJECT_NAME} test_package.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE  ${ITK_LIBRARIES} )
#itksys is already linked through dependencies of ITKCommon but we also want to check name alias
target_link_libraries(${PROJECT_NAME} PRIVATE ITK::itksys)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_11)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
            ${CMAKE_CURRENT_SOURCE_DIR}/test.mha
            ${CMAKE_CURRENT_BINARY_DIR}/test.mha
    COMMENT "Copying test.mha to ${TARGET_DIR}"
)
