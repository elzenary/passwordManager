cmake_minimum_required(VERSION 3.16)
project(PasswordManager LANGUAGES CXX)


# Require C++17 or newer
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Source files
set(SOURCES
src/main.cpp
src/VaultManager.cpp
src/CredentialManager.cpp
src/CLI.cpp
)


set(HEADERS
include/CredentialData.h
include/ICredentialService.h
include/VaultManager.h
include/CredentialManager.h
include/CLI.h
)


# Create executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


target_include_directories(${PROJECT_NAME}
PRIVATE
${CMAKE_CURRENT_SOURCE_DIR}/include
)


# Optional: link against crypto libs later (OpenSSL, libsodium)
# find_package(OpenSSL REQUIRED)
# target_link_libraries(${PROJECT_NAME} PRIVATE OpenSSL::Crypto)


# Installation rule (optional)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)