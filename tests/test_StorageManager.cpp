#include "StorageManager.hpp"
#include <cassert>
#include <iostream>
#include <string>

int main() {
    StorageManager<int> nums;
    nums.add(10);
    nums.add(20);
    nums.add(30);
    assert(nums.size() == 3);
    assert(nums.get(1) == 20);

    StorageManager<int> moved = std::move(nums);
    assert(nums.size() == 0);
    assert(moved.size() == 3);

    moved.clear();
    assert(moved.size() == 0);

    StorageManager<std::string> texts;
    texts.add("Hello");
    texts.add(std::string("World"));
    assert(texts.size() == 2);
    assert(texts.get(0) == "Hello");

    texts.clear();
    assert(texts.size() == 0);

    std::cout << "StorageManager tests passed!\n";
    return 0;
}