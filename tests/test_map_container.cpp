#include "map_container.hpp"
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v{1,2,3};
    auto r = map_container(v, [](int x){ return x * 2.5; });
    assert(r.size() == 3);
    assert(r[0] == 2.5 && r[1] == 5.0 && r[2] == 7.5);

    std::vector<std::string> s{"a","bc","def"};
    auto lens = map_container(s, [](const std::string& t){ return static_cast<int>(t.size()); });
    assert((lens == std::vector<int>{1,2,3}));

    auto r2 = map_container(std::vector<int>{4,5}, [](int x){ return x + 1; });
    assert((r2 == std::vector<int>{5,6}));

    std::cout << "map_container tests passed\n";
    return 0;
}