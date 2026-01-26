/*
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
*/
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            diff=min(diff,arr[i]-arr[i-1]);   //here you will get the min absolute difference
        }

        //for storing pairs of absolute difference
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==diff){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};
