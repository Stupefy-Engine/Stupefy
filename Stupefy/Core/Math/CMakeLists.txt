# Math CMakeLists.txt

target_sources(Stupefy
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/math_functions.h
        ${CMAKE_CURRENT_LIST_DIR}/matrix3.cpp
        ${CMAKE_CURRENT_LIST_DIR}/matrix3.h
        ${CMAKE_CURRENT_LIST_DIR}/quaternions.cpp
        ${CMAKE_CURRENT_LIST_DIR}/quaternions.h
        ${CMAKE_CURRENT_LIST_DIR}/vector2.cpp
        ${CMAKE_CURRENT_LIST_DIR}/vector2.h
        ${CMAKE_CURRENT_LIST_DIR}/vector3.cpp
        ${CMAKE_CURRENT_LIST_DIR}/vector3.h
)