#include <iostream>
#include <cmath>

typedef unsigned long long ulong;

const ulong nfactors(const ulong n) {
    ulong ret = 0;
	ulong sq = sqrt(n);
    for(ulong i = sq; i >= 1; ret += n % i == 0 ? 2 : 0, i--);
	if(sq * sq == n) ret--; // perfect squares
    return ret;
}

int main() {
    ulong triangle = 1;
    ulong i = 2;
    ulong f = 1;
    while(f < 500) {
        triangle += i++;
        f = nfactors(triangle);
    }
    std::cout << "Solution is " << triangle << std::endl;
    return 0;
}
