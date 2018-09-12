#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned int uint;
using std::vector;

vector<uint> sieve(const uint n) {
    vector<uint> primes;
    vector<bool> a(n);
    uint p;
    for(p = 2; p < n; p++) {
        if(!a[p]) {
            primes.push_back(p);
            for(uint i = p * p; i < n; i += p) a[i] = true;
        }
    }
    return primes;
}

template<typename T>
bool isWholeNumber(const T&& val) {
    return floor(val) == val;
}

// Check all values from offset to offset + N
uint solve(uint N, uint offset=0) {
    vector<uint> primes = sieve(N + offset);

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
