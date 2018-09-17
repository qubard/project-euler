#include <iostream>

int main() {
    typedef unsigned int uint;
    uint solution = 0;
    const uint N = 1000; // all multiples below N
    for (uint i = 0; i < N; i ++) {
        if (i % 5 == 0 || i % 3 == 0) { 
            solution += i;
        }
    }
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
