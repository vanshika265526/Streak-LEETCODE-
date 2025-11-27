/*
. Maximum Subarray Sum With Length Divisible by K

You are given an array of integers nums and an integer k.

Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 */

class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> minPref(k, LLONG_MAX);

        long long prefix = 0;
        long long ans = LLONG_MIN;

        // prefix before starting: remainder 0 → value = 0
        minPref[0] = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            // remainder of current prefix position
            int r = (i + 1) % k;

            // if we have seen a prefix with same remainder
            if (minPref[r] != LLONG_MAX) {
                ans = max(ans, prefix - minPref[r]);
            }

            // update the minimum prefix for this remainder
            minPref[r] = min(minPref[r], prefix);
        }

        return ans;
    }
};
