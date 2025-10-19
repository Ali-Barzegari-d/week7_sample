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
        data.push_back(value);
    }

    void add(T&& value) {
        data.push_back(std::move(value));
    }

    T get(size_t index) const {
        if (index >= data.size())
            throw std::out_of_range("Index out of range");
        return data[index];
    }

    size_t size() const noexcept {
        return data.size();
    }

    void clear() noexcept {
        data.clear();
    }

    StorageManager(StorageManager&& other) noexcept
        : data(std::move(other.data)) {}

    StorageManager& operator=(StorageManager&& other) noexcept {
        if (this != &other) {
            data = std::move(other.data);
        }
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
        items.push_back(s);
    }

    void add(std::string&& s) {
        items.push_back(std::move(s));
    }

    std::string get(size_t index) const {
        if (index >= items.size())
            throw std::out_of_range("Index out of range");

        auto it = items.begin();
        std::advance(it, index);
        return *it;
    }

    size_t size() const noexcept {
        return items.size();
    }

    void clear() noexcept {
        items.clear();
    }

    StorageManager(StorageManager&& other) noexcept
        : items(std::move(other.items)) {}

    StorageManager& operator=(StorageManager&& other) noexcept {
        if (this != &other) {
            items = std::move(other.items);
        }
        return *this;
    }

    StorageManager(const StorageManager&) = delete;
    StorageManager& operator=(const StorageManager&) = delete;
};