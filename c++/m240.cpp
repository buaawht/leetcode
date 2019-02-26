//
// Created by buaawht on 2019-02-26.
//
#include "util.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n - 1;

        while (row < m && col >= 0) {
            int ele = matrix[row][col];

            if (ele == target) {
                return true;
            }

            while (row < m && col >= 0 && matrix[row][col] > target) {
                col--;
            }

            while (row < m && col >= 0 && matrix[row][col] < target) {
                row++;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v =
            {
                    {1,  4,  7,  11, 15},
                    {2,  5,  8,  12, 19},
                    {3,  6,  9,  16, 22},
                    {10, 13, 14, 17, 24},
                    {18, 21, 23, 26, 30}
            };
    cout << s.searchMatrix(v, 5) << endl;
    cout << s.searchMatrix(v, 20) << endl;

}
