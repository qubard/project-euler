#include <iostream>
#include <cmath>

typedef unsigned long long ulong;

bool isPrime(ulong n) {
    if(n % 2 == 0) return false;
    for(ulong i = sqrt(n); i > 1; i--) if(n % i == 0) return false;
    return true;
}

int main() {
    ulong val = (ulong) 600851475143;
    ulong i;
    for(i = sqrt(val); i > 1; i--) {
        if(val % i == 0 && isPrime(i)) break;
    }
    std::cout << "Solution is " << i << std::endl;
    return 0;
}

