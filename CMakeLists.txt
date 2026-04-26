cmake_minimum_required(VERSION 3.31)
project(Tiny_sword)
set(CMAKE_CXX_STANDARD 20)

cmake_policy(SET CMP0057 NEW)

list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/sfml")

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp
        include/headers.h
        include/TextureManager.h
        include/Animator.h
        src/Animator.cpp
        include/Game.h
        src/Game.cpp
        include/Entity.h
        src/Entity.cpp
        include/Player.h
        src/Player.cpp
        include/Map.h
        src/Map.cpp
        include/Trees.h
        src/Trees.cpp
        include/Enemy.h
        src/Enemy.cpp
)

set(ASSETS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Tiny Swords (Free Pack)")

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory "${ASSETS_DIR}" "$<TARGET_FILE_DIR:${PROJECT_NAME}>/assets"  VERBATIM)


target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(

        ${PROJECT_NAME}
        PRIVATE
        SFML::System
        SFML::Window
        SFML::Graphics
        SFML::Audio
)