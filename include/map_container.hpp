#pragma once
#include <vector>
#include <type_traits>
#include <iterator>
#include <utility>
#include <functional>

// map_container
// - Accepts any Container with begin()/end() and a unary callable f.
// - Returns std::vector<Result> where Result is decltype(f(*begin(container)))
// - Use perfect-forwarding for the callable.

template <typename Container, typename F>
auto map_container(const Container& c, F&& f)
    -> std::vector<std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>>
{
    using Result = std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>;

    std::vector<Result> out;
    // TODO: reserve appropriate capacity
    // TODO: iterate over c, call f on each element, and push result to out
    return out;
}

template <typename Container, typename F>
auto map_container(Container&& c, F&& f)
    -> std::vector<std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>>
{
    using Result = std::decay_t<decltype(std::declval<F>()(*std::begin(c)))>;

    std::vector<Result> out;
    // TODO: reserve appropriate capacity
    // TODO: iterate over std::forward<Container>(c), call f, push results
    return out;
}
