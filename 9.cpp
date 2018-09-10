#include <iostream>
#include <cmath>

int main() {
    typedef unsigned int uint;
    for(uint a = 1; a < 1000; a++) {
        for(uint c = a + 1; c < 1000; c++) {
            uint asq = a * a;
            uint csq = c * c;
            uint bsq = csq - asq;
            double b = sqrt(bsq);
            if(b > a && b < c && a + b + c == 1000) { 
                std::cout << "Solution is " << a * (uint) b * c << std::endl; // 31875000
            }  
        }    
    }
    return 0;
}
