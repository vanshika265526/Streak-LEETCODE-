/*
You are given an integer array nums. In one operation, you can add or subtract 1 from any element of nums.

Return the minimum number of operations to make all elements of nums divisible by 3.
*/

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        //for to be divisible by 3, x%3==0, x%3=1, x%3=2 only possible
        //for 0,3  its fine, for 1 we will subtract 1 and make it 0, for 2 we will add 1 and make zero, so  totaloperations becomes numbers of elements NOT divisible by 3

        int result=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%3!=0){    //just simply count the number of elements not divible by 3 = number of operations
                result++;
            }
        }
        return result;
    }
};
