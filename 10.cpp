#include <iostream>
#include <cmath>

typedef unsigned long long ulong;

inline bool isPrime(ulong n) {
    if(n % 2 == 0) return false;
    for(ulong i = sqrt(n); i > 1; i--) if(n % i == 0) return false;
    return true;
}

// avoided using a sieve since it takes input n, prime generator? doesn't seem to matter
int main() {
    ulong solution = 0;
    for(ulong i = 2; i < 2000000; i++) {
        if(isPrime(i)) solution += i;
    }
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
