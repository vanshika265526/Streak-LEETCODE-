/*
You are given an integer array nums with the following properties:

nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

 

Example 1:

Input: nums = [1,2,3,3]
Output: 3
Example 2:

Input: nums = [2,1,2,5,3,2]
Output: 2
  */

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int a=nums.size()/2;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        for(auto i:freq){
            if(i.second==a){
                return i.first;
            }
        }
        return -1;
    }
};
