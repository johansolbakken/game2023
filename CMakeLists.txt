cmake_minimum_required(VERSION 3.5)

project(game)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/assimp)

file(GLOB_RECURSE SOURCES "src/**.cpp" "src/**.h")
add_executable(game ${SOURCES})
target_include_directories(game PUBLIC "src"
                                       "vendor/glfw/include"
                                       "vendor/glm"
                                       "vendor/assimp/include"
                                        "vendor/stb_image/include")
target_link_libraries(game glfw assimp)



add_custom_command(TARGET game POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:game>/assets)