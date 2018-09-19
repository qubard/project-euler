#include <iostream>
#include <cassert>
#include <array>
#include <cmath>

size_t divisor_sum(size_t n) {
    size_t ret = 0;
    for (size_t i = n - 1; i > 0; i--) {
        if (n % i == 0) ret += i;
    }
    return ret;
}

bool is_abundant(size_t n) {
    return divisor_sum(n) > n;
}

template<size_t N>
bool can_be_written(size_t n, std::array<bool, N>& table) {
    for (int i = n / 2; i > 0; i--) {
        if (table[i] && table[n - i]) {
            return true;
        }
    }
    return false;
}

int main() {
    assert(divisor_sum(28) == 28);
    assert(divisor_sum(12) == 16);

    size_t solution = 0;
    const size_t max_a = 28123;

    std::array<bool, max_a> table; // table[i] true iff i is abundant
    for (size_t i = 1; i < max_a; i++) table[i] = is_abundant(i);
    for (size_t i = 1; i < max_a; solution += can_be_written(i, table) ? 0 : i, i++);
    std::cout << "Solution is " << solution << "\n";
    return 0;
}
