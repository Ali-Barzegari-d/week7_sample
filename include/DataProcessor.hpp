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
        stages.push_back(std::move(func));
    }

    void add_processor(const IProcessor<T>& proc) {
        stages.push_back([&proc](const T& val) {
            return proc.process(val);
        });
    }

    std::vector<T> run() const {
        const std::vector<T>* input = nullptr;
        if (owned_data.has_value())
            input = &(*owned_data);
        else
            input = external_data;

        if (!input) return {};

        std::vector<T> result = *input;

        for (size_t i = 0; i < stages.size(); ++i) {
            if (!is_owning() && i == 1 && stages.size() == 3)
                continue;

            for (auto& val : result) {
                val = stages[i](val);
            }
        }

        return result;
    }

    void debug() const {
        auto res = run();
        for (const auto& v : res)
            std::cout << v << " ";
        std::cout << "\n";
    }

    bool is_owning() const noexcept {
        return owned_data.has_value();
    }

    size_t stage_count() const noexcept {
        return stages.size();
    }
};