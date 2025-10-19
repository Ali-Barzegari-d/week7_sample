#pragma once
#include <vector>
#include <functional>
#include <iostream>
#include <stdexcept>

template <typename T>
class NumericPipeline {
private:
    std::vector<T> data;
    std::vector<std::function<T(const T&)>> stages;

public:
    NumericPipeline() = default;
    explicit NumericPipeline(std::vector<T> input);

    void add_stage(std::function<T(const T&)> func); 
    std::vector<T> run() const;                      
    void clear_stages();                             
    bool empty() const noexcept;                     
    void print() const;                              
};
