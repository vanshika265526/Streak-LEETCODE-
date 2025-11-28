/*
There is an undirected tree with n nodes labeled from 0 to n - 1. 
You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge 
between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting 
components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> tree;
    int ans = 0;
    int k;

    long long dfs(int node, int parent, vector<int>& values) {
        long long total = values[node]; // use long long here
        for (int nei : tree[node]) {
            if (nei != parent) { // avoid going back to parent
                long long child_sum = dfs(nei, node, values);
                if (child_sum % k == 0) {
                    ans++; // we can cut this edge
                } else {
                    total += child_sum;
                }
            }
        }
        return total;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k_) {
        k = k_;
        tree.assign(n, vector<int>());
        for (auto &e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        dfs(0, -1, values);
        return ans + 1; // +1 for the remaining component
    }
};
