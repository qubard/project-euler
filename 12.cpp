#include <iostream>
#include <cmath>

typedef unsigned long long ulong;

const ulong factors(const ulong n) {
    ulong ret = 0;
    for(ulong i = sqrt(n); i >= 1; i--) {
        if(n % i == 0) {
            ret += 2;
        }
    }
    return ret;
}

int main() {
    ulong triangle = 1;
    ulong i = 2;
    ulong f = 1;
    while(f < 500) {
        triangle += i++;
        f = factors(triangle);
    }
    std::cout << "Solution is " << triangle << std::endl;
    return 0;
}
