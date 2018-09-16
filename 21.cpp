#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

size_t d(size_t n) {
    size_t ret = 0;
    size_t divisor = sqrt(n);
    std::vector<bool> arr(n + 1); // kinda dumb but it'll do
    while(divisor >= 1) {
        if(n % divisor == 0){ 
            if(!arr[divisor]) {
                arr[divisor] = true;
                ret += divisor;
            }

            size_t other_divisor = n / divisor;
            if(!arr[other_divisor]) {
                arr[other_divisor] = true;
                ret += other_divisor;
            }
        }
        divisor--;
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
