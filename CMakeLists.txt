cmake_minimum_required(VERSION 3.10.0)
project(PhysicsEngine VERSION 0.1.0 LANGUAGES C CXX)

find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

add_executable(PhysicsEngine 
src/main.cpp

src/math.cpp
src/matrix.cpp
src/PhysicsEngine.cpp
src/Circle.cpp
src/Chain.cpp
src/calculate_Force.cpp
src/calculate_collisions.cpp
src/Rectangle.cpp
src/vec.cpp

headers/math.h
headers/matrix.h
headers/PhysicsEngine.h
headers/Circle.h
headers/Chain.h
headers/calculate_Force.h
headers/calculate_collisions.h
headers/Rectangle.h
headers/vec.h
headers/Object.h

tests/test.cpp
)


include_directories(
headers 
src 
tests
)



target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-network
    sfml-audio
)
