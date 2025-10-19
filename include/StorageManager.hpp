#pragma once
#include <vector>
#include <list>
#include <type_traits>
#include <utility>
#include <stdexcept>
#include <string>

template <typename T, typename Enable = void>
class StorageManager;

template <typename T>
class StorageManager<T, std::enable_if_t<std::is_arithmetic_v<T>>> {
private:
    std::vector<T> data;

public:
    StorageManager() = default;

    void add(const T& value) {
        // TODO: add value to data
    }

    void add(T&& value) {
        // TODO: move value into data
    }

    T get(size_t index) const {
        // TODO: return element at index, throw std::out_of_range if invalid
        return {};
    }

    size_t size() const noexcept {
        // TODO: return size
        return 0;
    }

    void clear() noexcept {
        // TODO: clear all data
    }

    StorageManager(StorageManager&& other) noexcept {
        // TODO: move construct
    }

    StorageManager& operator=(StorageManager&& other) noexcept {
        // TODO: move assign
        return *this;
    }

    StorageManager(const StorageManager&) = delete;
    StorageManager& operator=(const StorageManager&) = delete;
};

template <>
class StorageManager<std::string> {
private:
    std::list<std::string> items;

public:
    StorageManager() = default;

    void add(const std::string& s) {
        // TODO: push_back
    }

    void add(std::string&& s) {
        // TODO: move and push_back
    }

    std::string get(size_t index) const {
        // TODO: access nth element from list
        return {};
    }

    size_t size() const noexcept {
        // TODO: return list size
        return 0;
    }

    void clear() noexcept {
        // TODO: clear the list
    }

    StorageManager(StorageManager&& other) noexcept {
        // TODO: move construct
    }

    StorageManager& operator=(StorageManager&& other) noexcept {
        // TODO: move assign
        return *this;
    }

    StorageManager(const StorageManager&) = delete;
    StorageManager& operator=(const StorageManager&) = delete;
};
