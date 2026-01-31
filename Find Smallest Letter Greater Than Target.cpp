/*
You are given an array of characters letters that is sorted in non-decreasing order, and a character target. There are at least two different characters in letters.

Return the smallest character in letters that is lexicographically greater than target. If such a character does not exist, return the first character in letters.

 

Example 1:

Input: letters = ["c","f","j"], target = "a"
Output: "c"
Explanation: The smallest character that is lexicographically greater than 'a' in letters is 'c'.
Example 2:

Input: letters = ["c","f","j"], target = "c"
Output: "f"
Explanation: The smallest character that is lexicographically greater than 'c' in letters is 'f'.
  */

//METHOD 1
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++){
            if(letters[i]>target){
                return letters[i];
            }
        }
        return letters[0];
    }
};


//METHOD2
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, r = letters.size() - 1;
        char ans = letters[0];

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (letters[mid] > target) {
                ans = letters[mid];
                r = mid - 1;  // try to find smaller greater
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
