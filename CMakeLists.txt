cmake_minimum_required(VERSION 3.16)
project(PasswordManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------------------------------------------------
# libsodium setup
# -------------------------------------------------------------------
if(WIN32)
    message(STATUS "Using prebuilt MinGW libsodium for Windows")

    set(LIBSODIUM_ROOT
        ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/libsodium-1.0.20-stable-mingw/libsodium-win64
    )

    set(LIBSODIUM_INCLUDE_DIR
        ${LIBSODIUM_ROOT}/include
    )

    # Prefer static .a — it works cleanly with MinGW
    set(LIBSODIUM_LIB
        ${LIBSODIUM_ROOT}/lib/libsodium.a
    )

else() # Linux / macOS
    message(STATUS "Using system libsodium for Linux")

    find_path(LIBSODIUM_INCLUDE_DIR sodium.h PATH_SUFFIXES sodium)
    find_library(LIBSODIUM_LIB sodium)

    if(NOT LIBSODIUM_INCLUDE_DIR OR NOT LIBSODIUM_LIB)
        message(FATAL_ERROR "libsodium not found. Install: sudo apt install libsodium-dev")
    endif()

endif()

# -------------------------------------------------------------------
# Sources
# -------------------------------------------------------------------
set(SOURCES
    src/main.cpp
    src/VaultManager.cpp
    src/CredentialManager.cpp
    src/CLI.cpp
    src/SecurityManager.cpp
    src/crypto.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# -------------------------------------------------------------------
# Include directories
# -------------------------------------------------------------------
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${LIBSODIUM_INCLUDE_DIR}
)

# -------------------------------------------------------------------
# Link libsodium
# -------------------------------------------------------------------
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${LIBSODIUM_LIB}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
