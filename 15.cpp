#include <iostream>
#include <vector>

typedef unsigned long long ulong;
typedef unsigned int uint;

// This solution is arrived at after deriving a basic recurrence for n = 2, also there's a tractable solution
// involving BigInts and computing (2n!)/(n!)^2
// But finding the recurrence then creating a dynamic programming solution is easier

int main() {
    constexpr size_t dimension = 20;
    std::vector<std::vector<ulong>> dp(dimension + 1, std::vector<ulong>(dimension + 1));

    for (uint i = 0; i < dimension + 1; i++) { 
        dp[i][dimension] = 1;
        dp[dimension][i] = 1;
    }

    for (int y = dimension - 1; y >= 0; y--) { // don't make x, y unsigned!! -1 wraps to 2^32 - 1 and causes an infinite loop
        for (int x = dimension - 1; x >= 0; x--) {
            dp[y][x] = dp[y][x + 1] + dp[y + 1][x];
        }
    }
    std::cout << "Solution is " << dp[0][0] << std::endl;
    return 0;
}
