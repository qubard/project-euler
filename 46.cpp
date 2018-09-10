#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned int uint;
typedef std::vector<uint> vint;
typedef std::vector<bool> vbool;

vint sieve(uint n) {
    vint primes;
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

template <class T>
bool isWholeNumber(T&& val) {
    return floor(val) == val;
}

// Check all values from offset to offset + N
uint solve(uint N, uint offset=0) {
    vint primes = sieve(N + offset);

    // Go through all i and see if it doesn't have a matching N for a given prime <= i
    for(uint i = 3; i < N; i += 2) {
        uint val = i + offset;
        bool skip = false;
        for(uint& prime : primes) {
            if(prime <= val && isWholeNumber(sqrt((val-prime)/2))) { // Solve for N in 2*N^2
                skip = true;
                break;
            }
        }

        if(!skip) return i;
    }
    return -1;
}

int main() {
    uint N = 10000000;
    std::cout << "Solution is " << solve(N) << std::endl;
    return 0;
}
