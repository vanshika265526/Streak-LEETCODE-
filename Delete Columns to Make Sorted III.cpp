/*
We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

Suppose we chose a set of deletion indices answer such that after deletions, 
the final array has every string (row) in lexicographic order. (i.e., (strs[0][0] <= strs[0][1] <= ... <= strs[0][strs[0].length - 1]),
and (strs[1][0] <= strs[1][1] <= ... <= strs[1][strs[1].length - 1]), and so on). Return the minimum possible value of answer.length.
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();          // number of rows
        int m = strs[0].size();       // number of columns
        
        vector<int> dp(m, 1);
        int lis = 1;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool valid = true;
                
                // check ordering for ALL rows
                for (int r = 0; r < n; r++) {
                    if (strs[r][j] > strs[r][i]) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            lis = max(lis, dp[i]);
        }
        
        return m - lis;
    }
};
