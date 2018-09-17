#include <iostream>

int main() {
    size_t a = 1;
    size_t b = 2;
    size_t c = a + b;
    size_t sum = b;
    while (c < 4000000) {
        if (c % 2 == 0) sum += c;
        a = b;
        b = c;
        c = a + b;
    }
    std::cout << "Solution is " << sum << std::endl;
    return 0;
}
