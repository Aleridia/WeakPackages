CMAKE_MINIMUM_REQUIRED(VERSION 3.30)
project(WeakPackage-c)

# Set C standard
set(CMAKE_C_STANDARD 99)

# Add executables
add_executable(vulnerable_project main.c database.c)

# Add SQLite3 if required
find_package(SQLite3 REQUIRED)
target_link_libraries(vulnerable_project SQLite::SQLite3)

# Link OpenSSL with a known vulnerable version (e.g., OpenSSL 1.0.1)
find_library(OPENSSL_LIBRARIES NAMES ssl PATHS /usr/lib /usr/local/lib)
include_directories(/usr/include /usr/local/include)
target_link_libraries(vulnerable_project ${OPENSSL_LIBRARIES})