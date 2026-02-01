/*
You are given an array of integers nums of length n.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into 3 disjoint contiguous subarrays.

Return the minimum possible sum of the cost of these subarrays.*/

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int count=nums[0];
        //first element will always be part of sum

        //sort from 1th index now
        sort(nums.begin()+1,nums.end());
        //add 2nd and 3rd min element into count
        count=nums[1]+nums[2];
        return count;
    }
};


//METHOD 2
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < first) {
                second = first;
                first = nums[i];
            } else if (nums[i] < second) {
                second = nums[i];
            }
        }

        return nums[0] + first + second;
    }
};

