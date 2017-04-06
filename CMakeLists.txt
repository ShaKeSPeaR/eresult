cmake_minimum_required(VERSION 3.4)
project(eresult)

#-----------------------------------------------------------------
#project global variables

if( MSVC )
    cmake_policy(SET CMP0020 NEW)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)

#-----------------------------------------------------------------
#project defines

if( MSVC )
    add_definitions(-D_USE_MATH_DEFINES)
    add_definitions(-D_USE_32BIT_TIME_T)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
    add_definitions(-D_UNICODE)
    add_definitions(-DUNICODE)
    add_definitions(-DWIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  /EHsc /MP")
else()
    add_definitions( -Wall -Wno-reorder)
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )
    set( CMAKE_CXX_STANDARD 14 )
endif()

#-----------------------------------------------------------------
#source list 

file(GLOB ERES_LIST
            ./main.cpp )

#-----------------------------------------------------------------
#final executables
add_executable( ${PROJECT_NAME}  ${ERES_LIST} )
