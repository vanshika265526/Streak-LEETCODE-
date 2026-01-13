/*
You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted multiple times.
*/

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e18, high = 0;

        for (auto &s : squares) {
            double y = s[1], l = s[2];
            low = min(low, y);
            high = max(high, y + l);
        }

        auto balance = [&](double h) {
            long double below = 0, above = 0;

            for (auto &s : squares) {
                double y = s[1], l = s[2];
                double top = y + l;

                if (h <= y) {
                    above += l * l;
                } 
                else if (h >= top) {
                    below += l * l;
                } 
                else {
                    below += l * (h - y);
                    above += l * (top - h);
                }
            }

            return above - below;
        };

        for (int i = 0; i < 80; i++) {
            double mid = (low + high) / 2.0;
            if (balance(mid) > 0)
                low = mid;     // need to go up
            else
                high = mid;    // too high, go down
        }

        return low;
    }
};
