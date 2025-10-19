#include "NumericPipeline.hpp"
#include <cassert>
#include <iostream>

int main() {
    NumericPipeline<int> pipe({1, 2, 3, 4, 5});

    pipe.add_stage([](int x){ return x + 2; });
    pipe.add_stage([](int x){ return x * 3; });
    pipe.add_stage([](int x){ return x - 1; });

    auto result = pipe.run();
    assert((result == std::vector<int>{8, 11, 14, 17, 20}));

    pipe.print();
    assert(!pipe.empty());

    pipe.clear_stages();
    assert(pipe.empty());

    std::cout << "✅ NumericPipeline tests passed!\n";
    return 0;
}
