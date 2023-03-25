cmake_minimum_required(VERSION 3.0)

project(HelloWorld)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/glad)
add_subdirectory(vendor/assimp)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(game ${SOURCES})
target_include_directories(game PUBLIC "src"
                                       "vendor/glfw/include"
                                       "vendor/glad/include"
                                       "vendor/glm"
                                       "vendor/assimp/include")
target_link_libraries(game glfw glad assimp)