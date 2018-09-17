#include <iostream>
#include <vector>

typedef unsigned int uint;
using std::vector;

vector<uint> sieve(const uint n) {
    vector<uint> primes;
    vector<bool> a(n);
    uint p;
    for (p = 2; p < n; p++) {
        if (!a[p]) {
            primes.push_back(p);
            for (uint i = p * p; i < n; i += p) a[i] = true;
        }
    }
    return primes;
}

int main() {
    std::cout << "Solution is " << sieve(10000000)[10000] << std::endl; // 104743, 1st prime is at index 0
    return 0;
}
