/*
You are given an n x n integer matrix. You can do the following operation any number of times:

Choose any two adjacent elements of matrix and multiply each of them by -1.
Two elements are considered adjacent if and only if they share a border.

Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int negativeCount = 0;
        int minAbs = INT_MAX;

        for (auto &row : matrix) {
            for (int val : row) {
                if (val < 0) negativeCount++;
                totalSum += abs(val);
                minAbs = min(minAbs, abs(val));
            }
        }

        // If odd number of negatives, one smallest absolute value must stay negative
        if (negativeCount % 2 == 1) {
            totalSum -= 2LL * minAbs;
        }

        return totalSum;
    }
};
