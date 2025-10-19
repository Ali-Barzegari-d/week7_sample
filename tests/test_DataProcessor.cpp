#include "DataProcessor.hpp"
#include <cassert>
#include <iostream>
#include <vector>

template <typename T>
class MultiplyProcessor : public IProcessor<T> {
    T factor;
public:
    explicit MultiplyProcessor(T f) : factor(f) {}
    T process(const T& value) const override { return value * factor; }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    DataProcessor<int> borrowed(nums);
    borrowed.add_stage([](const int& x){ return x + 1; });
    borrowed.add_stage([](const int& x){ return x * 2; });
    MultiplyProcessor<int> mul3(3);
    borrowed.add_processor(mul3);
    assert(!borrowed.is_owning());
    assert(borrowed.stage_count() == 3);

    auto result1 = borrowed.run();
    assert((result1 == std::vector<int>{6,9,12,15,18}));

    std::vector<int> owned_data = {10, 20, 30};
    DataProcessor<int> owned(std::move(owned_data));
    owned.add_stage([](const int& x){ return x / 2; });
    MultiplyProcessor<int> mul2(2);
    owned.add_processor(mul2);
    assert(owned.is_owning());

    auto result2 = owned.run();
    assert((result2 == std::vector<int>{10,20,30}));

    owned.debug();

    std::cout << "DataProcessor tests passed!\n";
    return 0;
}