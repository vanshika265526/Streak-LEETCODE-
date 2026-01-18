/*
A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
  */

class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> row(m, vector<int>(n + 1, 0));
        vector<vector<int>> col(m + 1, vector<int>(n, 0));
        vector<vector<int>> diag(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> anti(m + 1, vector<int>(n + 1, 0));
        
        // Build prefix sums
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                row[i][j + 1] = row[i][j] + grid[i][j];
                col[i + 1][j] = col[i][j] + grid[i][j];
                diag[i + 1][j + 1] = diag[i][j] + grid[i][j];
                anti[i + 1][j] = anti[i][j + 1] + grid[i][j];
            }
        }
        
        // Try all sizes from large to small
        for (int k = min(m, n); k >= 2; k--) {
            for (int i = 0; i + k <= m; i++) {
                for (int j = 0; j + k <= n; j++) {
                    
                    int target = row[i][j + k] - row[i][j];
                    bool magic = true;
                    
                    // Check rows
                    for (int r = i; r < i + k && magic; r++) {
                        if (row[r][j + k] - row[r][j] != target)
                            magic = false;
                    }
                    
                    // Check columns
                    for (int c = j; c < j + k && magic; c++) {
                        if (col[i + k][c] - col[i][c] != target)
                            magic = false;
                    }
                    
                    // Check diagonals
                    int d1 = diag[i + k][j + k] - diag[i][j];
                    int d2 = anti[i + k][j] - anti[i][j + k];
                    
                    if (d1 != target || d2 != target)
                        magic = false;
                    
                    if (magic) return k;
                }
            }
        }
        
        return 1; // At least 1x1 is always magic
    }
};
