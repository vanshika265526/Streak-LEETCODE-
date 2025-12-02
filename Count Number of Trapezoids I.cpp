/*

You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.

A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.

Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.

Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
public:
    long long countTrapezoids(vector<vector<int>>& points) {
        const long long MOD = 1e9 + 7;
        
        unordered_map<long long, long long> cnt;
        for (auto &p : points) {
            cnt[p[1]]++;
        }

        vector<long long> segs;
        for (auto &it : cnt) {
            long long c = it.second;
            if (c >= 2) {
                segs.push_back((c * (c - 1) / 2) % MOD);
            }
        }

        long long S = 0;      // sum of a_i
        long long S2 = 0;     // sum of a_i^2

        for (long long x : segs) {
            S = (S + x) % MOD;
            S2 = (S2 + (x * x) % MOD) % MOD;
        }

        long long res = ( (S * S) % MOD - S2 + MOD ) % MOD;
        // divide by 2 using modular inverse of 2
        long long inv2 = 500000004; // (MOD+1)/2 for 1e9+7
        return (res * inv2) % MOD;
    }
};
