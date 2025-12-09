/*
You are given an integer array nums.

A special triplet is defined as a triplet of indices (i, j, k) such that:

0 <= i < j < k < n, where n = nums.length
nums[i] == nums[j] * 2
nums[k] == nums[j] * 2
Return the total number of special triplets in the array.

Since the answer may be large, return it modulo 109 + 7.
  */

class Solution {
public:
    int specialTriplets(vector<int>& nums) {

        // MOD value to prevent overflow since answer can be very large
        const long long MOD = 1e9 + 7;

        // This map stores frequency of numbers that are to the RIGHT of j
        unordered_map<long long, long long> rightMap;

        // This map stores frequency of numbers that are to the LEFT of j
        unordered_map<long long, long long> leftMap;

        // First, we put ALL numbers into rightMap
        // Because initially, j has not started moving
        // So everything is considered on the right side
        for (int i = 0; i < nums.size(); i++) {
            rightMap[nums[i]]++;   // increase frequency
        }

        // This variable will store the final answer
        long long answer = 0;

        // Now we move j from left to right through the array
        for (int j = 0; j < nums.size(); j++) {

            long long mid = nums[j];   // current middle element

            // Since nums[j] is now the middle,
            // it should NOT be counted on the right side anymore
            rightMap[mid]--;

            // We calculate what value we need on both left and right
            // because nums[i] == 2 * nums[j] and nums[k] == 2 * nums[j]
            long long target = 2 * mid;

            // Find how many times this target appears on the LEFT side
            long long leftCount = leftMap[target];

            // Find how many times this target appears on the RIGHT side
            long long rightCount = rightMap[target];

            // The total triplets formed with this j as the middle is:
            // (choices on left) × (choices on right)
            answer = (answer + (leftCount * rightCount) % MOD) % MOD;

            // Now we add the current element into the leftMap
            // So that it can be used for future j values
            leftMap[mid]++;
        }

        // Finally return the answer
        return answer;
    }
};
