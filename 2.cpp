#include <iostream>

int main() {
    typedef unsigned int uint;
    uint a = 1;
    uint b = 2;
    uint c = a + b;
    uint sum = b;
    while(c < 4000000) {
        if(c % 2 == 0) sum += c;
        a = b;
        b = c;
        c = a + b;
    }
    std::cout << "Solution is " << sum << std::endl;
    return 0;
}
