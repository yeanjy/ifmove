# Author Jota, oederaugusto
# date September 28, 2023.
# version September 29, 2023

cmake_minimum_required(VERSION 2.8.5...3.27.6)
project(ifmove)

# CMake settings
# generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")


# Find packages
find_package(SDL2 REQUIRED)
find_package(Doxygen)
# =-=-=-=

# =-=-=-=-=-=-= DOCS =-=-=-=-=-=-=-=
if (DOXYGEN_FOUND)
    message("Doxygen is enabled")

    add_custom_target(
        doc
        COMMAND ${DOXYGEN_EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
else (DOXYGEN_FOUND)
    message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# =-=-=-=-=-=-= LIBRARY =-=-=-=-=-=-=
# set the output directory that the .so file (library file) will be compiled
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# Source files
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(
    SOURCE_FILES
    ${SOURCE_DIR}/arrow2.cpp
    ${SOURCE_DIR}/game.cpp
    ${SOURCE_DIR}/gcircle.cpp
    ${SOURCE_DIR}/gmesh2.cpp
    ${SOURCE_DIR}/gparticle.cpp
    ${SOURCE_DIR}/graphics.cpp
    ${SOURCE_DIR}/grid.cpp
    ${SOURCE_DIR}/gsquare.cpp
    ${SOURCE_DIR}/gtriangle.cpp
    ${SOURCE_DIR}/mesh2.cpp
    ${SOURCE_DIR}/mesh2_utils.cpp
    ${SOURCE_DIR}/MultiCircleCollision.cpp
    ${SOURCE_DIR}/particle.cpp
    ${SOURCE_DIR}/point2.cpp
    ${SOURCE_DIR}/sdl.cpp
    ${SOURCE_DIR}/shape.cpp
    ${SOURCE_DIR}/window.cpp
)

# add a shared library with name "ifmove" using files: SOURCE_FILES
add_library(ifmove SHARED ${SOURCE_FILES})

# linking libraries to "ifmove". SDL2_LIBRARIES variable is set when running
# "find_package(SDL2 REQUIRED)" in line 11
target_link_libraries(
    ifmove
    PRIVATE
    ${SDL2_LIBRARIES}
)

# set the includes folder. SDL2_INCLUDE_DIRS variable set when running
# find_package
target_include_directories(
    ifmove
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)
# =-=-=-=

# =-=-=-=-=-=-= TESTS =-=-=-=-=-=-=
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# For new test files just copy the lines 81 to 105 and paste below. Remember to
# change the names of the executables and source files

# =-=-= window_test =-=-=
# Adding executables for testing with name "window_test" using file:
# "tests/window_test.cpp"
add_executable(window_test tests/window_test.cpp)

# Libraries
target_link_directories(
    window_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    window_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    window_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= acceleration_test =-=-=
# Adding executables for testing
add_executable(acceleration_test tests/acceleration_test.cpp)

# Libraries
target_link_directories(
    acceleration_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    acceleration_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    acceleration_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= matrix_test =-=-=
# Adding executables for testing
add_executable(matrix_test tests/matrix_test.cpp)

# Libraries
target_link_directories(
    matrix_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    matrix_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    matrix_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= particle_test =-=-=
# Adding executables for testing
add_executable(particle_test tests/particle_test.cpp)

# Libraries
target_link_directories(
    particle_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    particle_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    particle_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= vector3_test =-=-=
# Adding executables for testing
add_executable(vector3_test tests/vector3_test.cpp)

# Libraries
target_link_directories(
    vector3_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    vector3_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    vector3_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= game_test =-=-=
# Adding executables for testing
add_executable(game_test tests/game_test.cpp)

# Libraries
target_link_directories(
    game_test
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    game_test
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    game_test
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)

# =-=-= MultiCircleCollision =-=-=
# Adding executables for testing
add_executable(MultipleCircleCollision tests/MultipleCircleCollision_test.cpp)

# Libraries
target_link_directories(
    MultipleCircleCollision
    PRIVATE
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
)
target_link_libraries(
    MultipleCircleCollision
    PRIVATE
    ifmove
    ${SDL2_LIBRARIES}
)

# Header files
target_include_directories(
    MultipleCircleCollision
    PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${SDL2_INCLUDE_DIRS}
)
