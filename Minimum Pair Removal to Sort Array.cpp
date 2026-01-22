/*
Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 */
class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while(!isSorted(nums)) {
            int minSum = INT_MAX;
            int idx = 0;

            // find leftmost minimum-sum adjacent pair
            for(int i = 0; i < nums.size() - 1; i++) {
                if(nums[i] + nums[i+1] < minSum) {
                    minSum = nums[i] + nums[i+1];
                    idx = i;
                }
            }

            // replace the pair with their sum
            nums[idx] = nums[idx] + nums[idx+1];
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }
};
