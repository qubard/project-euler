#include <iostream>
#include <array>
#include <vector>
#include <numeric>
#include <cassert>

template<size_t N>
std::string generateWord(const int n, const std::array<std::string, N>& words) {
   int cn = n;
   int ones = cn % 10; 
   int tens = (cn /= 10) % 10; 
   int hundreds = (cn /= 10) % 10; 
   int thousands = (cn /= 10) % 10;

   if (n < 20 || words[n] != "") {
       return words[n];
   }

   if (n >= 10 && n < 100) {
       return words[10 * tens] + "-" + generateWord(n - 10 * tens, words);
   }

   if (n >= 100 && n < 1000) {
        return words[hundreds] + " hundred and " + generateWord(n - 100 * hundreds, words);
   }

   return "Invalid!";
}

size_t count_characters(const std::string&& str) {
    return std::accumulate(str.begin(), str.end(), (size_t)0, [](size_t& a, const char& b) { if (b != ' ' && b != '-') return (size_t)(a + 1); return (size_t)a; });
}

int main() {
    std::array<std::string, 1001> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty" };
    words[30] = "thirty";
    words[40] = "forty";
    words[50] = "fifty";
    words[60] = "sixty";
    words[70] = "seventy";
    words[80] = "eighty";
    words[90] = "ninety";
    words[100] = "one hundred";
    words[200] = "two hundred";
    words[300] = "three hundred";
    words[400] = "four hundred";
    words[500] = "five hundred";
    words[600] = "six hundred";
    words[700] = "seven hundred";
    words[800] = "eight hundred";
    words[900] = "nine hundred";
    words[1000] = "one thousand";
    assert(count_characters(generateWord(342, words)) == 23);
    assert(count_characters(generateWord(115, words)) == 20);
    size_t solution = 0;
    for (int i = 1; i <= 1000; i++) {
        solution += count_characters(generateWord(i, words));
    }
    std::cout << "Solution is " << solution << std::endl; // 21124
    return 0;
}
