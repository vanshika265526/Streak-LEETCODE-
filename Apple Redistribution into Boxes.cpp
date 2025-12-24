/*
You are given an array apple of size n and an array capacity of size m.

There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

Note that, apples from the same pack can be distributed into different boxes.

 

Example 1:

Input: apple = [1,3,2], capacity = [4,3,1,5,2]
Output: 2
Explanation: We will use boxes with capacities 4 and 5.
It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
Example 2:

Input: apple = [5,5,5], capacity = [2,4,2,7]
Output: 4
Explanation: We will need to use all the boxes.
  */

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        //basically this wants to see how many number of boxes are required to fill your total apples. So for that first count your total apples and sort your boxes in descending order and then start a loop to keep checking for the point where the apples sum is finally equal to or less than the capcacity sum of boxes. That gives you your number of boxes
        int totalApples=0;
        int n=apple.size();
        int m=capacity.size();
        for(int i=0;i<n;i++){
            totalApples+=apple[i];
        }

        sort(capacity.begin(), capacity.end(), greater<int>()); //for descending order


        int checkSum=0;
        for(int i=0;i<capacity.size();i++){
            checkSum+=capacity[i];
            if(checkSum>=totalApples){
                return i+1;
            }

        }
        return -1;
    }
};
