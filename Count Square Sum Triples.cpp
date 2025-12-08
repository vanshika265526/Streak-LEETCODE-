/*
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Example 1:
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
  */

class Solution {
public:
    int countTriples(int n) {
        int count=0; //keeps track of number of counts
      
        //do it by pythagoras theorem= works for sum triples also because same concept

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){      //initialte two loops for i and j value
                int c=(i*i)+(j*j);      //compute i^2+j^2 value
                int c1=sqrt(c);      //take square root of c because by above formula it is c^2

                if(c1*c1==c && c1<=n) count++;     //now if squareroot is >n and pythagoras is valid, increase the count.
            } 
        }
    return count;    //return the counted value
    }
};
