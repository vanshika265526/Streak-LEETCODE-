class Solution {
public:
    int countBits(int n){
        int count=0;
        while(n){
            if(n&1) count++;
            n=n>>1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),[&](int a,int b){
        int countA=countBits(a);
        int countB=countBits(b);
        if(countA==countB){
            return a<b;
            }
        return countA< countB;
        });
        return arr;
        
    }
};


vector<int> sortByBits(vector<int>& arr) {
    sort(arr.begin(), arr.end(), [](int a, int b) {
        if (__builtin_popcount(a) == __builtin_popcount(b))
            return a < b;
        return __builtin_popcount(a) < __builtin_popcount(b);
    });
    return arr;
}
