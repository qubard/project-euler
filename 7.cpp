#include <iostream>
#include <vector>

typedef unsigned int uint;
typedef std::vector<uint> vint;
typedef std::vector<bool> vbool;

vint sieve(uint n) {
    vint primes = {2};
    vbool a(n);
    uint p;
    for(p = 2; p < n;) {
        for(uint i = p; i < n; i += p) a[i] = true;

        uint i;
        for(i = p+1; i < n; i++) {
            if(!a[i]) {
                primes.push_back(p = i);
                break;
            }
        }

        // No new prime found
        if(i == n) break;
    }
    return primes;
}

int main() {
    std::cout << "Solution is " << sieve(10000000)[10000] << std::endl; // 104743, 1st prime is at index 0
    return 0;
}