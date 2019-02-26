#include "util.h"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size();
        if (m == 0) {
            return false;
        }

        int n = matrix[0].size();
        if (n == 0) {
            return false;
        }

        int N = m * n;

        int high = N - 1;
        int low = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m;
            int col = mid % n;
            int ele = matrix[row][col];
            if (ele == target) {
                return true;
            } else if (ele > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }


    bool searchMatrix1(vector<vector<int>> &matrix, int target) {
        // treat the matrix as an array, just taking care of indices
        // [0..n*m]
        // (row, col) -> row*n + col
        // i -> [i/n][i%n]
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int e = matrix[mid / n][mid % n];
            if (target < e) {
                end = mid - 1;
            } else if (target > e) {
                start = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};


int main() {
    vector<vector<int>> v = {{1},
                             {1}};

    Solution s;
    cout << s.searchMatrix(v, 2) << endl;
    cout << s.searchMatrix(v, 15) << endl;
    cout << s.searchMatrix(v, 3) << endl;
    return 0;
}
