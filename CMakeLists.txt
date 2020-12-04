# Author: Sylvester Agyiri

# Cmake version needed to build this project
cmake_minimum_required(VERSION 3.15)

# Project name
project(Multiplayer_Game)

# The include directory for SFML header files
include_directories(include)

# The library directory for SFML shared library
link_directories(lib)

# Output executable format for linux
add_executable(client1 client1.cpp)

# Output executable format for linux
add_executable(client2 client2.cpp)

# Link the libraries to the executable file
target_link_libraries(client1 -lsfml-window -lsfml-system -lsfml-graphics -lglad_gl)

# Link the libraries to the executable file
target_link_libraries(client2 -lsfml-window -lsfml-system -lsfml-graphics -lglad_gl)

# Set the folder to store the executable format
set_target_properties(client1 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY bin/
)

# Set the folder to store the executable format
set_target_properties(client2
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY bin/
)