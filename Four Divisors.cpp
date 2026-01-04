/*
Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors.
If there is no such integer in the array, return 0.
  */

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;         // current answer starting from 0
        for (int n : nums) { // looping through each  number
            int count = 0;   // number of divisiors of this particular number
            int sum = 0;     // sum of divisors of this particular number
            for (int i = 1; i * i <= n; i++) {
                if (n % i == 0) {
                    int d1 = i;
                    int d2 = n / i;
                    if (d1 == d2) {
                        count++;
                        sum += d1;
                    } else {
                        count += 2;
                        sum += d1 + d2;
                    }
                    if (count > 4)
                        break; 
                }
            }

            if (count == 4)
                ans += sum;
        }

        return ans;
    }
};
