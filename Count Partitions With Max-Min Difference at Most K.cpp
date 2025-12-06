/*
You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

Return the total number of ways to partition nums under this condition.

Since the answer may be too large, return it modulo 109 + 7.

 

Example 1:

Input: nums = [9,4,1,3,7], k = 4

Output: 6

Explanation:

There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

[[9], [4], [1], [3], [7]]
[[9], [4], [1], [3, 7]]
[[9], [4], [1, 3], [7]]
[[9], [4, 1], [3], [7]]
[[9], [4, 1], [3, 7]]
[[9], [4, 1, 3], [7]]

*/


class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<long long> dp(n+1, 0), pref(n+1, 0);
        dp[0] = 1;
        pref[0] = 1;
        
        deque<int> minD, maxD;
        int left = 0;
        
        for(int right = 0; right < n; right++) {
            
            while(!minD.empty() && nums[minD.back()] >= nums[right])
                minD.pop_back();
            minD.push_back(right);
            
            while(!maxD.empty() && nums[maxD.back()] <= nums[right])
                maxD.pop_back();
            maxD.push_back(right);
            
            // shrink from left until valid
            while(!minD.empty() && !maxD.empty() &&
                  nums[maxD.front()] - nums[minD.front()] > k) {
                if(minD.front() == left) minD.pop_front();
                if(maxD.front() == left) maxD.pop_front();
                left++;
            }
            
            // dp[right+1] = sum of dp[left ... right]
            long long total = pref[right];
            if(left > 0) total = (total - pref[left-1] + MOD) % MOD;
            dp[right+1] = total;
            
            pref[right+1] = (pref[right] + dp[right+1]) % MOD;
        }
        
        return dp[n];
    }
};
