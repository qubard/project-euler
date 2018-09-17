#include <iostream>

typedef unsigned int uint;

int main() {
    uint v;
    bool ok;
    for (v = 21; v < 1000000000; v++, ok = true) {
        for (uint i = 2; i < 20; i++, ok = ok & (v % i == 0));
        if (ok) break;
    }
    std::cout << "Solution is " << v << std::endl; // 232792560
    return 0;
}
