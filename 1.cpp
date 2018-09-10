#include <iostream>

int main() {
    typedef unsigned int uint;
    uint solution = 0;
    uint N = 1000; // all multiples below N
    for(uint i = 0; i < N; i += 3) solution += i;
    for(uint i = 0; i < N; i+= 5) solution += i;
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
