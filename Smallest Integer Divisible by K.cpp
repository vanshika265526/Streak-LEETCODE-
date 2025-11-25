/*
Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

Return the length of n. If there is no such n, return -1.

Note: n may not fit in a 64-bit signed integer.
  */

class Solution {
public:
    int smallestRepunitDivByK(int k) {

      //first, a number ending with 1 is never divisible by 2 and 5 so return -1 for this case
        if (k % 2 == 0 || k % 5 == 0) return -1;

      //Case 2: mark a remainder variable
        int remainder = 0;
      //taking length<=k because using modulo and modulo cant go above value of k(obviously)
        for (int length = 1; length <= k; length++) {
          //find for every value
            remainder = (remainder * 10 + 1) % k;
            //if divisible return it, otherwise keep iterating
            if (remainder == 0)
                return length;
        }
  
        return -1;
    }
};
