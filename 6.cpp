#include <iostream>

// From Calculus/Math we get i(i+1)(2i+1)/6 = \sum i^2 and (i^4+2i^3+i^2)/4 for sum of squares, so we get an O(1) calculation

int main() {
    typedef unsigned int uint;
    uint i = 100;
    uint isq = i*i;
    uint solution = (isq*isq + 2*i*isq + isq)/4 - i*(i+1)*(2*i+1)*1/6;
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
