/*You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.
*/

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &x, auto &y){
            if (x[1] == y[1]) return x[0] > y[0];
            return x[1] < y[1];
        });

        int res = 0;
        int a = -1, b = -1;  // last two picked numbers

        for (auto &v : intervals) {
            int l = v[0], r = v[1];

            bool aIn = (a >= l && a <= r);
            bool bIn = (b >= l && b <= r);

            if (aIn && bIn) {
                // we already have 2 numbers inside
                continue;
            }
            else if (aIn) {
                // only a is inside  need one more number
                res += 1;
                b = a;
                a = r;  // choose the end
            }
            else {
                // neither inside  need 2 new numbers
                res += 2;
                b = r - 1;
                a = r;
            }
        }

        return res;
    }
};
