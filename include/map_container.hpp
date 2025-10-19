#pragma once
#include <vector>
#include <type_traits>
#include <iterator>
#include <utility>
#include <functional>

// map_container
// - Accepts any Container with begin()/end() and a unary callable f.
// - Returns std::vector<Result> where Result is decltype(f(*begin(container)))

template <typename Container, typename F>
auto map_container(const Container& c, F&& f)
    -> std::vector<std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>>
{
    using Result = std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>;
    std::vector<Result> out;
    out.reserve(std::size(c)); 

    for (const auto& elem : c) {
        out.push_back(std::invoke(std::forward<F>(f), elem));
    }
    return out;
}

template <typename Container, typename F>
auto map_container(Container&& c, F&& f)
    -> std::vector<std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>>
{
    using Result = std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>;
    std::vector<Result> out;
    out.reserve(std::size(c)); 

    for (auto&& elem : std::forward<Container>(c)) {
        out.push_back(std::invoke(std::forward<F>(f), std::forward<decltype(elem)>(elem)));
    }
    return out;
}