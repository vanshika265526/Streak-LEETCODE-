/*
Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.

Recall that the number of set bits an integer has is the number of 1's present when written in binary.

For example, 21 written in binary is 10101, which has 3 set bits.
  */
class Solution {
public:
    int countbits(int number){
        int count=0;
        while(number>0){
            if(number%2==1){
                count++;
            }
            number=number/2;
        }
        return count;

    }
    int countPrimeSetBits(int left, int right) {
        int total=0;
        for(int i=left;i<=right;i++){
            int currentbit=countbits(i);
            if(currentbit==2 || currentbit==3 || currentbit==5 || currentbit==7 || currentbit==11 || currentbit==13 || currentbit==17 || currentbit==19){
                total++;
            }
        }
        return total;
        
    }
};
