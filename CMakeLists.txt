cmake_minimum_required(VERSION 3.10)
# Forțăm atât compilatorul de C cât și cel de C++ să folosească g++

project(MY_GAME)
add_subdirectory(raylib)

#Adaugam implementarile  
file(GLOB GAME_SOURCE "Implementari/*.cpp"  )

#Adaugam executabilul 
add_executable( game  ${GAME_SOURCE})
set_target_properties( game PROPERTIES LINKER_LANGUAGE CXX)

#Targetam headerele 
target_include_directories( game PRIVATE
    raylib/src
    Resurse
    Implementari
)

target_link_libraries(game PRIVATE raylib)

if(WIN32)
    target_link_libraries(game PRIVATE opengl32 gdi32 winmm)
endif()