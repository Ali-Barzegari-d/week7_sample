#include "NumericPipeline.hpp"

template <typename T>
NumericPipeline<T>::NumericPipeline(std::vector<T> input)
    : data(std::move(input)) {}

template <typename T>
void NumericPipeline<T>::add_stage(std::function<T(const T&)> func) {
    // TODO: append stage to the list
}

template <typename T>
std::vector<T> NumericPipeline<T>::run() const {
    // TODO:
    // 1. Make a copy of data
    // 2. Apply all stages sequentially
    // 3. Return the transformed result
    return {};
}

template <typename T>
void NumericPipeline<T>::clear_stages() {
    // TODO
}

template <typename T>
bool NumericPipeline<T>::empty() const noexcept {
    // TODO
    return false;
}

template <typename T>
void NumericPipeline<T>::print() const {
    // TODO: print all values separated by space
}

// Explicit instantiation
template class NumericPipeline<int>;
template class NumericPipeline<double>;
