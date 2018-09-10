#include <iostream>
#include <string>
#include <algorithm>

typedef unsigned int uint;

int main() {
    uint solution = 1;
    for(uint a = 999; a > 1; a--) {
        for(uint b = 1; b < a; b++) {
            uint res = a * b;
            std::string palindrome = std::to_string(res);
            std::string original = std::string(palindrome);
            std::reverse(palindrome.begin(), palindrome.end());
            if(res > solution && palindrome == original) {
                solution = res;
            }
        }
    }
    std::cout << "Solution is " << solution << std::endl; // 993*913 = 906609
    return 0;
}
