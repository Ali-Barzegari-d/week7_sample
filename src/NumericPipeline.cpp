#include "NumericPipeline.hpp"

template <typename T>
NumericPipeline<T>::NumericPipeline(std::vector<T> input)
    : data(std::move(input)) {}

template <typename T>
void NumericPipeline<T>::add_stage(std::function<T(const T&)> func) {
    stages.push_back(std::move(func));
}

template <typename T>
std::vector<T> NumericPipeline<T>::run() const {
    if (data.empty())
        throw std::runtime_error("Pipeline data is empty");

    std::vector<T> result = data;

    for (auto& stage : stages) {
        for (auto& val : result)
            val = stage(val);
    }

    return result;
}

template <typename T>
void NumericPipeline<T>::clear_stages() {
    stages.clear();
}

template <typename T>
bool NumericPipeline<T>::empty() const noexcept {
    return stages.empty();
}

template <typename T>
void NumericPipeline<T>::print() const {
    std::cout << "Data: ";
    for (const auto& val : data)
        std::cout << val << " ";
    std::cout << std::endl;
}

template class NumericPipeline<int>;
template class NumericPipeline<double>;
