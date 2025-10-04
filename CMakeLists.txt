cmake_minimum_required(VERSION 3.12)
project(Game)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(raylib)

# Collect all source files
file(GLOB SOURCES
    "*.c"
    "*.cpp"
)

# Create the executable
add_executable(game ${SOURCES})

# Link raylib to executable
target_link_libraries(game raylib)

if(UNIX)
    #find_package(X11 REQUIRED)
    #target_link_libraries(game
    #${X11_LIBRARIES}
    #OpenGL
    #pthread
    #dl
    #m
    #target_include_directories(game PRIVATE ${X11_INCLUDE_DIR})
endif()

# Windows
if (WIN32)
    target_link_libraries(game
        opengl32
        gdi32
        winmm
    )
endif()
