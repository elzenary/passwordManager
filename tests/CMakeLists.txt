cmake_minimum_required(VERSION 3.15)
project(PasswordManager_UnitTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ---- Paths ----
set(PROJECT_ROOT_DIR ${CMAKE_SOURCE_DIR}/..)       # since this file is in project_root/tests/
set(PROJECT_INCLUDE_DIR ${PROJECT_ROOT_DIR}/include)
set(PROJECT_SRC_DIR ${PROJECT_ROOT_DIR}/src)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# ---- Catch2 submodule (thirdparty/catch2) ----
# EXCLUDE_FROM_ALL so it's not built automatically unless used
add_subdirectory(${PROJECT_ROOT_DIR}/thirdparty/catch2 ${CMAKE_BINARY_DIR}/catch2 EXCLUDE_FROM_ALL)

# Enable CTest integration
enable_testing()

# ---------------------------
# Helper function: add one unit test target
# ---------------------------
function(add_unit_test TARGET_NAME)
    cmake_parse_arguments(UT "" "UNIT_SRC" "TEST_SRCS;MOCK_DIR" ${ARGN})

    # Check arguments
    if(NOT UT_UNIT_SRC)
        message(FATAL_ERROR "add_unit_test: UNIT_SRC is required for target ${TARGET_NAME}")
    endif()
    if(NOT UT_TEST_SRCS)
        message(FATAL_ERROR "add_unit_test: TEST_SRCS is required for target ${TARGET_NAME}")
    endif()

    # Compose absolute paths
    set(unit_src_path ${PROJECT_ROOT_DIR}/${UT_UNIT_SRC})

    # Collect test sources (relative to tests dir)
    set(test_files)
    foreach(t IN LISTS UT_TEST_SRCS)
        list(APPEND test_files ${TESTS_DIR}/${t})
    endforeach()

    # Collect mocks (optional)
    set(mock_files)
    if(UT_MOCK_DIR)
        file(GLOB mock_files ${TESTS_DIR}/${UT_MOCK_DIR}/*.cpp)
    endif()

    # Define the test executable
    add_executable(${TARGET_NAME}
        ${unit_src_path}
        ${test_files}
        ${mock_files}
    )

    # Include directories
    target_include_directories(${TARGET_NAME} PRIVATE
        ${PROJECT_INCLUDE_DIR}
        ${TESTS_DIR}
    )
    if(UT_MOCK_DIR)
        target_include_directories(${TARGET_NAME} PRIVATE ${TESTS_DIR}/${UT_MOCK_DIR})
    endif()

    # Link against Catch2 (Catch2 provides main)
    target_link_libraries(${TARGET_NAME} PRIVATE Catch2::Catch2WithMain)

    # Register test with CTest
    add_test(NAME ${TARGET_NAME} COMMAND ${TARGET_NAME})
endfunction()

# ---------------------------
# Per-module unit tests
# ---------------------------

# ✅ CredentialManager unit test
add_unit_test(test_credential_manager
    UNIT_SRC src/CredentialManager.cpp
    TEST_SRCS "credential_manager/test_credential_manager.cpp"
    MOCK_DIR "credential_manager/mocks"
)

#VaultManager test
add_unit_test(test_vault_manager
    UNIT_SRC src/VaultManager.cpp
    TEST_SRCS "vault_manager/test_vault_manager.cpp"
    MOCK_DIR "vault_manager/mocks"
)

# Example: CLI test (uncomment when ready)
# add_unit_test(test_cli
#     UNIT_SRC src/CLI.cpp
#     TEST_SRCS "cli/test_cli.cpp"
#     MOCK_DIR "cli/mocks"
# )
