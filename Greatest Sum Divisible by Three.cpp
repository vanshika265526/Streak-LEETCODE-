/*
Greatest Sum Divisible by Three
Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;
        int min1 = INT_MAX, secondMin1 = INT_MAX;
        int min2 = INT_MAX, secondMin2 = INT_MAX;

        for (int num : nums) {
            sum += num;
            if (num % 3 == 1) {
                if (num < min1) {
                    secondMin1 = min1;
                    min1 = num;
                } else if (num < secondMin1) {
                    secondMin1 = num;
                }
            } else if (num % 3 == 2) {
                if (num < min2) {
                    secondMin2 = min2;
                    min2 = num;
                } else if (num < secondMin2) {
                    secondMin2 = num;
                }
            }
        }

        int remainder = sum % 3;
        if (remainder == 0) return sum;
        else if (remainder == 1) {
            int option1 = (min1 != INT_MAX) ? sum - min1 : 0;
            int option2 = (min2 != INT_MAX && secondMin2 != INT_MAX) ? sum - min2 - secondMin2 : 0;
            return max(option1, option2);
        } else { // remainder == 2
            int option1 = (min2 != INT_MAX) ? sum - min2 : 0;
            int option2 = (min1 != INT_MAX && secondMin1 != INT_MAX) ? sum - min1 - secondMin1 : 0;
            return max(option1, option2);
        }
    }
};
