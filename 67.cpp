#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using std::vector;

typedef unsigned long long ulong;

ulong digit(const std::string&& s) {
    if(s.length() < 2) return 0;
    return 10 * (s[0] - '0') + (s[1] - '0');
}

int main() {
    constexpr int rows = 100;
    std::string inp;
    vector<vector<ulong>> tri(1);

    // redirect the text file as standard input eg. ./67 < p067_triangle.txt
    while(std::cin >> inp) {
        static int i = 1;
        tri[tri.size() - 1].push_back(digit(std::move(inp)));
        if(tri[tri.size() - 1].size() >= i) {
            i++;
            tri.push_back(vector<ulong>());
        }
    }

    for(int i = rows - 2; i >= 0; i--) {
        for(int j = 0; j < tri[i].size(); j++) {
            tri[i][j] = std::max(tri[i][j] + tri[i + 1][j], tri[i][j] + tri[i + 1][j + 1]);
        }
    }
    std::cout << "Solution is " << tri[0][0] << "\n";
    return 0;
}
