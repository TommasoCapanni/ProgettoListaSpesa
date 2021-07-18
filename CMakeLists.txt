cmake_minimum_required(VERSION 3.19)
project(ProgettoListaSpesa)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(test)

set(SOURCE_FILES Articolo.h Subject.h Observer.h ShoppingList.h User.h Display.h ShoppingList.cpp User.cpp NegativeNumberException.h)
add_executable(ProgettoListaSpesa main.cpp)
add_library(core ${SOURCE_FILES})
set_target_properties(core PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(ProgettoListaSpesa core)