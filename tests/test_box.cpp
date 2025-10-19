#include "box.hpp"
#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
int main() {
    Box<int> a(3), b(5);
    auto c = a + b;
    assert(c.get() == 8);

    assert(a < b);
    assert(b > a);
    assert(a != b);
    assert(!(a == b));

    Box<std::string> s1("Hello "), s2("World");
    auto s3 = s1 + s2;
    assert(s3.get() == "Hello World");

    std::ostringstream oss;
    oss << s3;
    assert(oss.str() == "[Hello World]");

    std::cout << "box tests passed\n";
    return 0;
}