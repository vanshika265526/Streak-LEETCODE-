class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        auto maxGap = [](vector<int>& bars) {
            sort(bars.begin(), bars.end());
            int longest = 1, curr = 1;

            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] == bars[i - 1] + 1) {
                    curr++;
                } else {
                    curr = 1;
                }
                longest = max(longest, curr);
            }
            return longest + 1; // gap = consecutive bars + 1
        };

        int hGap = maxGap(hBars);
        int vGap = maxGap(vBars);

        int side = min(hGap, vGap);
        return side * side;
    }
};
