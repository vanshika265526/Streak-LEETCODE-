/*
Along a long library corridor, there is a line of seats and decorative plants. You are given a 0-indexed string corridor of length n consisting of letters 'S' and 'P' where each 'S' represents a seat and each 'P' represents a plant.

One room divider has already been installed to the left of index 0, and another to the right of index n - 1. Additional room dividers can be installed. For each position between indices i - 1 and i (1 <= i <= n - 1), at most one divider can be installed.

Divide the corridor into non-overlapping sections, where each section has exactly two seats with any number of plants. There may be multiple ways to perform the division. Two ways are different if there is a position with a room divider installed in the first way but not in the second way.

Return the number of ways to divide the corridor. Since the answer may be very large, return it modulo 109 + 7. If there is no way, return 0.
  */

class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        
        long long totalSeats = 0;
        for (char c : corridor)
            if (c == 'S') totalSeats++;
        
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;
        
        long long ways = 1;
        long long seatCount = 0;
        long long plants = 0;
        
        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                
                // when we hit the first seat of the next section
                if (seatCount == 3) {
                    ways = (ways * (plants + 1)) % MOD;
                    plants = 0;
                    seatCount = 1;  // this seat becomes first seat of new section
                }
            } else {
                // count plants only between 2nd and 3rd seat
                if (seatCount == 2)
                    plants++;
            }
        }
        
        return ways;
    }
};
