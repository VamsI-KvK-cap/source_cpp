cmake_minimum_required(VERSION 3.10)
project(acme_atm VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(acme_atm 
    src/main.cpp
    src/atm.cpp
    src/account.cpp
)

# Include directories
target_include_directories(acme_atm PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Install target
install(TARGETS acme_atm DESTINATION bin)

# Enable testing
enable_testing()