/*
You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].

A building is covered if there is at least one building in all four directions: left, right, above, and below.

Return the number of covered buildings.
  */

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, vector<int>> rowMap, colMap;

    // Fill rowMap and colMap
    for (auto &b : buildings) {
        int x = b[0], y = b[1];
        rowMap[x].push_back(y);
        colMap[y].push_back(x);
    }

    // Sort each row and each column
    for (auto &p : rowMap) sort(p.second.begin(), p.second.end());
    for (auto &p : colMap) sort(p.second.begin(), p.second.end());

    int count = 0;

    for (auto &b : buildings) {
        int x = b[0], y = b[1];

        // Binary search in rowMap[x] for y
        auto &row = rowMap[x];
        auto &col = colMap[y];

        int yi = lower_bound(row.begin(), row.end(), y) - row.begin();
        int xi = lower_bound(col.begin(), col.end(), x) - col.begin();

        bool left  = yi > 0;
        bool right = yi < row.size() - 1;
        bool up    = xi > 0;
        bool down  = xi < col.size() - 1;

        if (left && right && up && down) {
            count++;
        }
    }

    return count;
}
};
