/*
Given an n x n binary grid, in one step you can choose two adjacent rows of the grid and swap them.

A grid is said to be valid if all the cells above the main diagonal are zeros.

Return the minimum number of steps needed to make the grid valid, or -1 if the grid cannot be valid.

The main diagonal of a grid is the diagonal that starts at cell (1, 1) and ends at cell (n, n).
*/
class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);
        for (int i = 0; i < n; ++i) {
            int cnt = 0, j = n-1;
            while (j >= 0 && grid[i][j] == 0) {
                cnt++;
                j--;
            }
            zeros[i] = cnt;
        }
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            int need = n - 1 - i;
            int j = i;
            while (j < n && zeros[j] < need) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j-1]);
                swaps++;
                j--;
            }
        }
        return swaps;
    }
};
