/*
You are given an array complexity of length n.

There are n locked computers in a room with labels from 0 to n - 1, each with its own unique password. The password of the computer i has a complexity complexity[i].

The password for the computer labeled 0 is already decrypted and serves as the root. All other computers must be unlocked using it or another previously unlocked computer, following this information:

You can decrypt the password for the computer i using the password for computer j, where j is any integer less than i with a lower complexity. (i.e. j < i and complexity[j] < complexity[i])
To decrypt the password for computer i, you must have already unlocked a computer j such that j < i and complexity[j] < complexity[i].
Find the number of permutations of [0, 1, 2, ..., (n - 1)] that represent a valid order in which the computers can be unlocked, starting from computer 0 as the only initially unlocked one.

Since the answer may be large, return it modulo 109 + 7.

Note that the password for the computer with label 0 is decrypted, and not the computer with the first position in the permutation.
  */

class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        // Pair complexity with index
        vector<pair<int,int>> nodes;
        for (int i = 0; i < n; i++)
            nodes.push_back({complexity[i], i});

        // Sort by complexity
        sort(nodes.begin(), nodes.end());

        // Fenwick Tree to track unlocked indices
        vector<int> bit(n + 1, 0);
        auto update = [&](int i){
            for (++i; i <= n; i += i & -i)
                bit[i]++;
        };
        auto query = [&](int i){
            int s = 0;
            for (++i; i > 0; i -= i & -i)
                s += bit[i];
            return s;
        };

        // Computer 0 is initially unlocked
        update(0);

        long long ans = 1;
        int available = 0;
        int ptr = 1;

        // First wave: who 0 can unlock
        while (ptr < n && nodes[ptr].first > complexity[0]) {
            available++;
            ptr++;
        }

        // If no one is available, dead
        if (available == 0 && n > 1) return 0;

        // Process unlocking
        for (int step = 1; step < n; step++) {
            ans = ans * available % MOD;

            // "Unlock" one computer deterministically
            int idx = nodes[step].second;
            update(idx);
            available--;

            // See who becomes newly unlockable
            while (ptr < n) {
                int i = nodes[ptr].second;
                // check if any unlocked j < i exists
                if (query(i - 1) > 0) {
                    available++;
                    ptr++;
                } else break;
            }

            if (available == 0 && step != n - 1) return 0;
        }

        return ans;
    }
};
