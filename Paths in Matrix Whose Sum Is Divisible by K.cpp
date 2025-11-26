/*
You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) 
and you want to reach position (m - 1, n - 1) moving only down or right.

Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {

                    int currentValue = grid[i][j];
                    int newRemainder = (r + currentValue) % k;

                    if (i > 0) {
                        dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i-1][j][r]) % MOD;
                    }
                    if (j > 0) {
                        dp[i][j][newRemainder] = (dp[i][j][newRemainder] + dp[i][j-1][r]) % MOD;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};
