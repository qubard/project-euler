#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
      tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string input;
    std::cin >> input;
    std::vector<std::string> tokens = split(input, ',');
    std::transform(tokens.begin(), tokens.end(), tokens.begin(), [](std::string& s) { // remove quotes
        return s.substr(1, s.length() - 2);
    });
    std::sort(tokens.begin(), tokens.end());
    size_t solution = 0;
    for (size_t i = 0; i < tokens.size(); i++) {
        auto& str = tokens[i];
        size_t val = (i + 1) * std::accumulate(str.begin(), str.end(), (size_t)0, [](size_t ret, char &a) { return ret + a - (size_t)'A' + 1; });
        solution += val;
    }
    std::cout << "Solution is " << solution << "\n";
    return 0;
}
