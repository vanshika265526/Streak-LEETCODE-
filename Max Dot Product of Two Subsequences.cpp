/*
Given two arrays nums1 and nums2.

Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

Example 1:

Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
Output: 18
Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
Their dot product is (2*3 + (-2)*(-6)) = 18.
  */

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));

        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                int product = nums1[i] * nums2[j];

                // Take this pair and possibly extend
                int takeBoth = product;
                if(i + 1 < n && j + 1 < m)
                    takeBoth += max(0, dp[i+1][j+1]);

                // Skip from nums1 or nums2
                int skip1 = dp[i+1][j];
                int skip2 = dp[i][j+1];

                dp[i][j] = max({takeBoth, skip1, skip2, product});
            }
        }

        return dp[0][0];
    }
};
