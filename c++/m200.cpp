/**
 *Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
 An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
 You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */
#include "util.h"
class Solution {
public:
    int walk(int &x, int &y, int d) {
        if (d == 0) {
            x++;
        } else if (d == 1) {
            x--;
        } else if (d == 2) {
            y++;
        } else {
            y--;
        }
        return 0;
    }

    bool could(int x, int y, int m, int n, vector <vector<bool>> &visit) {
        if (x < 0 || x >= m) {
            return false;
        }

        if (y < 0 || y >= n) {
            return false;
        }

        if (visit[x][y]) {
            return false;
        }
        return true;
    }

    int numIslands(vector <vector<char>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        vector <vector<bool>> visit(m, vector<bool>(n, 0));
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] || grid[i][j]!=1) {
                    continue;
                }
                visit[i][j] = true;
                queue<pair<int, int >> q;
                q.push(make_pair(i, j));


                while (!q.empty()) {
                    auto point = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int f = point.first;
                        int s = point.second;
                        walk(f, s, k);
                        if (!could(f, s, m, n, visit)) {
                            continue;
                        }
                        if (grid[f][s] == 1) {
                            q.push(make_pair(f, s));
                        }
                    }
                }
                sum++;

            }
        }
        return sum;
    }


};
