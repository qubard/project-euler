#include <iostream>
#include <vector>

typedef unsigned long long ulong;

int main() {
    const ulong n = 2000000;
    std::vector<bool> a(n);
    ulong solution = 0;
    for(ulong p = 2; p < n; p++) {
        if(!a[p]) {
            solution += p;
            for(ulong i = p * p; i < n; i += p) a[i] = true;
        }
    }
    std::cout << "Solution is " << solution << std::endl;
    return 0;
}
