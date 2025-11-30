#pragma once
#include <string>
#include <vector>
#include <cstring> // for memset
#include <iostream>

// ---------------------------------------------------------
// SecureString
// A wrapper around std::string that zeroes memory on destruction.
// Essential for storing passwords/keys in RAM.
// ---------------------------------------------------------
class SecureString {
private:
    std::vector<char> data_;

public:
    SecureString() = default;
    
    SecureString(const std::string& s) : data_(s.begin(), s.end()) {
        data_.push_back('\0');
    }

    // Move constructor
    SecureString(SecureString&& other) noexcept : data_(std::move(other.data_)) {}

    // Move assignment
    SecureString& operator=(SecureString&& other) noexcept {
        if (this != &other) {
            wipe();
            data_ = std::move(other.data_);
        }
        return *this;
    }

    // Delete copy to prevent accidental memory duplication
    SecureString(const SecureString&) = delete;
    SecureString& operator=(const SecureString&) = delete;

    ~SecureString() {
        wipe();
    }

    const char* c_str() const { return data_.data(); }
    bool empty() const { return data_.empty(); }

    // Explicit conversion to std::string (use carefully!)
    std::string toString() const {
        return data_.empty() ? "" : std::string(data_.data());
    }

private:
    void wipe() {
        if (!data_.empty()) {
            // Volatile prevents compiler optimization from skipping this
            volatile char* p = data_.data();
            size_t len = data_.size();
            while (len--) {
                *p++ = 0;
            }
        }
    }
};

