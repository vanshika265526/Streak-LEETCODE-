/*
Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).
*/
class Solution {
public:
    int countOdds(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            if(i%2!=0){
                count++;
            }
        }
        return count;
    }
};
