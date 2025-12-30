/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.*/

class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int r, int c) {
        // Center must be 5
        if (grid[r + 1][c + 1] != 5) return false;

        vector<int> freq(10, 0);

        // Check numbers are 1–9 and distinct
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int val = grid[i][j];
                if (val < 1 || val > 9 || freq[val]++) return false;
            }
        }

        // Check rows & columns
        for (int i = 0; i < 3; i++) {
            if (grid[r + i][c] + grid[r + i][c + 1] + grid[r + i][c + 2] != 15)
                return false;
            if (grid[r][c + i] + grid[r + 1][c + i] + grid[r + 2][c + i] != 15)
                return false;
        }

        // Check diagonals
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15)
            return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;

        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagic(grid, i, j)) count++;
            }
        }
        return count;
    }
};



