cmake_minimum_required(VERSION 3.22.1)
project(fortress)
set(CMAKE_CXX_STANDARD 23)

find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
if (ENABLE_CPPCHECK)
	if (CMAKE_CXX_CPPCHECK)
        list(
            APPEND CMAKE_CXX_CPPCHECK
			--quiet
			--enable=all
			--inconclusive
			--inline-suppr
			--suppress=missingIncludeSystem
			--template="{file}:{line}: {severity}: {message}\\n{code}"
			--template-location="{file}:{line}: note: {info}\\n{code}"
			--output-file=../cppcheck-report.txt
			${SOURCES}
		)
    endif()
endif()

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

include_directories("./include")
file(GLOB_RECURSE fortress_SOURCES src/*.cpp)

add_executable(fortress ${fortress_SOURCES})
target_link_libraries(fortress ${CURSES_LIBRARY})