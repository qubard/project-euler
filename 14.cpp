#include <iostream>

typedef unsigned long long ulong;

inline ulong collatz(ulong n) {
    ulong i = 1;
    for(; n != 1; n = n % 2 == 0 ? n / 2 : 3 * n + 1, i++);
    return i;
}

int main() {
    ulong solution = 0;
    ulong solution_i = 0;
    for (ulong i = 1; i < 1000000; i++) { 
        ulong c = collatz(i);
        if (c > solution) {
            solution = c;
            solution_i = i;
        }
    }
    std::cout << "Solution is " << solution_i << std::endl;
    return 0;
}
