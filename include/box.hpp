#pragma once
#include <type_traits>
#include <utility>
#include <iostream>
#include <sstream>

// Box<T>
// - Holds a single value of type T
// - Supports comparison (==, !=, <, >)
// - Supports addition (Box<T> + Box<T>) returning Box<Result>

template <typename T>
class Box {
    T value;

public:
    Box() = default;
    explicit Box(const T& v) : value(v) {}
    explicit Box(T&& v) noexcept(std::is_nothrow_move_constructible_v<T>)
        : value(std::move(v)) {}

    const T& get() const noexcept { return value; }

    bool operator==(const Box& other) const {
        // TODO
        return false;
    }

    bool operator!=(const Box& other) const {
        // TODO
        return false;
    }

    bool operator<(const Box& other) const {
        // TODO
        return false;
    }

    bool operator>(const Box& other) const {
        // TODO
        return false;
    }

    template <typename U = T>
    auto operator+(const Box<U>& other) const
        -> Box<decltype(std::declval<U>() + std::declval<U>())> {
        // TODO
        return Box<decltype(std::declval<U>() + std::declval<U>())>{};
    }

    friend std::ostream& operator<<(std::ostream& os, const Box& b) {
        // TODO: print value inside brackets like [value]
        return os;
    }
};
