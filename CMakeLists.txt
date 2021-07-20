cmake_minimum_required(VERSION 3.10)

# set the project name
project(Dino++)

# add the executable
file(GLOB dino_SRC
     "*.h"
     "*.cpp"
)

set(SFML_STATIC_LIBRARIES FALSE)
set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(SFML COMPONENTS graphics window system REQUIRED)
add_executable(Dino++ ${dino_SRC})
target_link_libraries(Dino++ sfml-graphics sfml-window sfml-system)
