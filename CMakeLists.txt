cmake_minimum_required(VERSION 3.0)
project(tetrominoes)
set(CMAKE_CXX_STANDARD 11)
add_executable(
    
    solCompiled
    foundationPile.cpp
    card.cpp
    tableau.cpp
    deck.cpp
    pile.cpp
    solDriver.cpp
)
