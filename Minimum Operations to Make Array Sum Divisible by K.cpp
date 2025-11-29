/*
You are given an integer array nums and an integer k. You can perform the following operation any number of times:

Select an index i and replace nums[i] with nums[i] - 1.
Return the minimum number of operations required to make the sum of the array divisible by k.

 */
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

      /*we are basically using the concept that first we will count the sum and then we will mod that
        sum with the given  number, whatever will be the remainder will be our min number of operations performed.*/
      
        int sum=0;
        for(int x:nums){
            sum+=x;     //finding total sum
        }
        sum=sum%k;   //taking mod
        return sum;    //returning the remainder=total number of operations
    }
};
