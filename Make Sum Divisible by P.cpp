/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.
  */
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total = (total + x) % p;

        int target = total % p;
        if (target == 0) return 0;  // no need to remove anything

        unordered_map<int,int> lastIndex;
        lastIndex[0] = -1;  // prefix before start
        
        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % p;

            
            long long need = (prefix - target + p) % p;

            if (lastIndex.count(need)) {
                ans = min(ans, i - lastIndex[need]);
            }

            lastIndex[prefix] = i;
        }

        return ans == nums.size() ? -1 : ans;
    }
};
