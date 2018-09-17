#include <iostream>

int main() {
    size_t solution = 0;
    const size_t N = 1000; // all multiples below N
    for (size_t i = 0; i < N; i ++) {
        if (i % 5 == 0 || i % 3 == 0) { 
            solution += i;
        }
    }
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
