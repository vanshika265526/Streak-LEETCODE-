/*
You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. 
Each row of blocks contains one less block than the row beneath it and is centered on top.

To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed.
A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, 
where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. 
Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed,
or false otherwise.
  */

class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> memo;

    bool dfs(string bottom) {
        // already solved this state
        if (memo.count(bottom)) return memo[bottom];

        // reached the top
        if (bottom.size() == 1)
            return memo[bottom] = true;

        bool possible = buildNext(bottom, 0, "");
        memo[bottom] = possible;
        return possible;
    }

    bool buildNext(string &bottom, int idx, string curr) {
        if (idx == bottom.size() - 1) {
            return dfs(curr);
        }

        string key = bottom.substr(idx, 2);
        if (mp.find(key) == mp.end()) return false;

        for (char ch : mp[key]) {
            if (buildNext(bottom, idx + 1, curr + ch))
                return true;
        }
        return false;
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (auto &s : allowed) {
            mp[s.substr(0, 2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
