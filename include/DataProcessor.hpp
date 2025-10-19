#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <iterator>
#include <type_traits>
#include <optional>

template <typename T>
class IProcessor {
public:
    virtual ~IProcessor() = default;
    virtual T process(const T& value) const = 0;
};

template <typename T>
class DataProcessor {
private:
    const std::vector<T>* external_data = nullptr;  
    std::optional<std::vector<T>> owned_data;       
    std::vector<std::function<T(const T&)>> stages; 

public:
    DataProcessor() = default;

    
    explicit DataProcessor(const std::vector<T>& data)
        : external_data(&data) {}

    
    explicit DataProcessor(std::vector<T>&& data)
        : owned_data(std::move(data)) {}


    void add_stage(std::function<T(const T&)> func) {
        // TODO: append stage
    }

   
    void add_processor(const IProcessor<T>& proc) {
        // TODO: wrap proc.process() into lambda and add to stages
    }

    // Run all stages sequentially on data (borrowed or owned)
    std::vector<T> run() const {
        // TODO:
        // 1. Get input range (from owned_data or external_data)
        // 2. Apply all stages to each element
        // 3. Return transformed vector
        return {};
    }

    void debug() const {
        // TODO: run and print each value
    }

    bool is_owning() const noexcept {
        // TODO
        return false;
    }

    size_t stage_count() const noexcept {
        // TODO
        return 0;
    }
};
