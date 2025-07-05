cmake_minimum_required(VERSION 3.10.0)
project(SoundClicker VERSION 0.1.0 LANGUAGES C)

add_executable(SoundClicker src/main.c)
target_link_libraries(SoundClicker winmm)

