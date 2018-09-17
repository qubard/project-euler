#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

vector<size_t> sieve(const size_t n) {
    vector<size_t> primes;
    vector<bool> a(n);
    size_t p;
    for (p = 2; p < n; p++) {
        if (!a[p]) {
            primes.push_back(p);
            for (size_t i = p * p; i < n; i += p) a[i] = true;
        }
    }
    return primes;
}

template<typename T>
bool isWholeNumber(const T&& val) {
    return floor(val) == val;
}

// Check all values from offset to offset + N
size_t solve(size_t N, size_t offset=0) {
    vector<size_t> primes = sieve(N + offset);

    // Go through all i and see if it doesn't have a matching N for a given prime <= i
    for (size_t i = 3; i < N; i += 2) {
        size_t val = i + offset;
        bool skip = false;
        for (size_t& prime : primes) {
            if (prime <= val && isWholeNumber(sqrt((val-prime)/2))) { // Solve for N in 2*N^2
                skip = true;
                break;
            }
        }
        if (!skip) return i;
    }
    return -1;
}

int main() {
    size_t N = 10000000;
    std::cout << "Solution is " << solve(N) << std::endl;
    return 0;
}
