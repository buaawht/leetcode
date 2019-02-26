#include "util.h"

class Solution {
public:
    int numSquares(int n) {
        int root = sqrt(n);
        if (root * root == n) {
            return 1;
        }

        int dp[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int temp = sqrt(i);
            int min_last = INT_MAX;
            for (int j = 1; j <= temp; j++) {
                min_last = min(min_last, dp[i - (j) * (j)]);
            }
            dp[i] = min_last + 1;

        }
        return dp[n];
    }
};


int main() {
    Solution s;

}
