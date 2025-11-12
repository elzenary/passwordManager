#include <catch2/catch_test_macros.hpp>
#include "VaultManager.h"
#include "CredentialData.h"
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

TEST_CASE("VaultManager saves and loads correctly", "[VaultManager]") {
    std::string testFile = "test_vault.txt";

    // Remove file if it exists from previous runs
    if (fs::exists(testFile)) fs::remove(testFile);

    VaultManager manager(testFile);

    // Prepare test data
    std::unordered_map<std::string, CredentialData> data = {
        {"gmail", {"user1", "pass1"}},
        {"github", {"user2", "pass2"}}
    };

    // Test saving
    REQUIRE(manager.save(data));

    // Test loading
    auto loaded = manager.load();

    REQUIRE(loaded.size() == 2);
    REQUIRE(loaded["gmail"].username == "user1");
    REQUIRE(loaded["gmail"].password == "pass1");
    REQUIRE(loaded["github"].username == "user2");
    REQUIRE(loaded["github"].password == "pass2");

    // Clean up
    fs::remove(testFile);
}
