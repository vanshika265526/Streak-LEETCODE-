/*
You are given an array of n strings strs, all of the same length.

We may choose any deletion indices, and we delete all the characters in those indices for each string.

For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.
*/
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int deletions = 0;
        
        vector<bool> sorted(n - 1, false);
        
        for (int col = 0; col < m; col++) {
            bool needDelete = false;
            
            // Check if this column breaks order
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] > strs[i + 1][col]) {
                    needDelete = true;
                    break;
                }
            }
            
            if (needDelete) {
                deletions++;
                continue;
            }
            
            // Update sorted status
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][col] < strs[i + 1][col]) {
                    sorted[i] = true;
                }
            }
        }
        
        return deletions;
    }
};

