#pragma once
#include <type_traits>
#include <utility>
#include <iostream>
#include <sstream>

template <typename T>
class Box {
private:
    T value;

public:
    Box() = default;
    explicit Box(const T& v) : value(v) {}
    explicit Box(T&& v) noexcept(std::is_nothrow_move_constructible_v<T>)
        : value(std::move(v)) {}

    const T& get() const noexcept { return value; }

    bool operator==(const Box& other) const {
        return value == other.value;
    }

    bool operator!=(const Box& other) const {
        return !(*this == other);
    }

    bool operator<(const Box& other) const {
        return value < other.value;
    }

    bool operator>(const Box& other) const {
        return value > other.value;
    }

    template <typename U = T>
    auto operator+(const Box<U>& other) const
        -> Box<decltype(std::declval<U>() + std::declval<U>())> {
        using ResultType = decltype(std::declval<U>() + std::declval<U>());
        return Box<ResultType>(value + other.get());
    }

    friend std::ostream& operator<<(std::ostream& os, const Box& b) {
        os << "[" << b.value << "]";
        return os;
    }
};