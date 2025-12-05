/*
You are given an integer array nums of length n.

A partition is defined as an index i where 0 <= i < n - 1, splitting the array into two non-empty subarrays such that:

Left subarray contains indices [0, i].
Right subarray contains indices [i + 1, n - 1].
Return the number of partitions where the difference between the sum of the left and right subarrays is even.
*/

class Solution {
public:
    int countPartitions(vector<int>& nums) {

      //very basic strategy- if total sum is even => all splits valid, if odd=>no splits are valid
        int total = 0;
        for (int x : nums) total += x;

        // If total sum is even, all n-1 splits are valid.  
        if (total % 2 == 0) return nums.size() - 1;      //basicallty if your total sum is even=> both either odd or both are even== every split is valid

        // Else no split works.
        return 0;    //if total sum is odd => basically means that left and right are diffrent(odd and even) which always gives odd result so 0
    }
};
