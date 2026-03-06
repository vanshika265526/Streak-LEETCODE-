/*
Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
*/

class Solution {
public:
    bool checkOnesSegment(string s) {
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == '1' && s[i-1] == '0') {
                return false;
            }
        }
        return true;
    }
};
