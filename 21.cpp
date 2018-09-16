#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

size_t d(size_t n) {
    size_t ret = 0;
    for(size_t divisor = n; divisor >= 1; divisor--) {
        if(n % divisor == 0){ 
            ret += divisor;
        }
    }
    return ret - n;
}

int main() {
    size_t solution = 0;
    assert(d(284) == 220);
    assert(d(220) == 284);
    for(size_t a = 1; a < 10000; a++) {
        size_t b = d(a);
        if(a != b && d(b) == a) {
            solution += a;
        }
    }
    std::cout << "Solution is " << solution << "\n";
    return 0;
}
