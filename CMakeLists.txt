cmake_minimum_required(VERSION 3.16)
project(Sciens)
set(CMAKE_CXX_STANDARD 14)

find_package(LLVM REQUIRED)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

include_directories(src)

add_executable(Sciens src/lexer.cpp src/lexer.h src/token.h src/compiler.cpp src/parser.cpp src/parser.h)

llvm_map_components_to_libnames(llvm_libs support core irreader)

# Link against LLVM libraries
target_link_libraries(Sciens ${llvm_libs})