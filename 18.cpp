#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

typedef unsigned long long ulong;

int main() {
    constexpr int rows = 15;
    vector<vector<ulong>> tri(rows);
    tri[0] = { 75 };
    tri[1] = { 95, 64 };
    tri[2] = { 17, 47, 82 };
    tri[3] = { 18, 35, 87, 10 };
    tri[4] = { 20, 4, 82, 47, 65 };
    tri[5] = { 19, 1, 23, 75, 3, 34 };
    tri[6] = { 88, 2, 77, 73, 7, 63, 67 };
    tri[7] = { 99, 65, 4, 28, 6, 16, 70, 92 };
    tri[8] = { 41, 41, 26, 56, 83, 40, 80, 70, 33 };
    tri[9] = { 41, 48, 72, 33, 47, 32, 37, 16, 94, 29 };
    tri[10] = { 53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14 };
    tri[11] = { 70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57 };
    tri[12] = { 91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48 };
    tri[13] = { 63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 41 };
    tri[14] = { 4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 24 };
	
    ulong solution = 0;
    for(int i = rows - 2; i >= 0; i--) {
        for(int j = 0; j < tri[i].size(); j++) {
            tri[i][j] = std::max(tri[i][j] + tri[i + 1][j], tri[i][j] + tri[i + 1][j + 1]);
        }
    }
    std::cout << "Solution is " << tri[0][0] << "\n";
    return 0;
}
