/*
You have n computers. You are given the integer n and a 0-indexed integer array batteries where the
ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

Initially, you can insert at most one battery into each computer. After that and at any integer time moment, 
you can remove a battery from a computer and insert another battery any number of times.
The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

Note that the batteries cannot be recharged.
  */
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long total = 0;
        for(long long x : batteries) total += x;

        long long low = 0, high = total / n;

        while(low < high){
            long long mid = (low + high + 1) / 2;
            long long usable = 0;

            for(long long b : batteries)
                usable += min(b, mid);

            if(usable >= mid * n)
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};
