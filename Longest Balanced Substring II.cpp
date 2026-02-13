class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int ans = 1;

        // Case 1: single character
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;
            ans = max(ans, count);
        }

        auto solveTwo = [&](char c1, char c2) {
            unordered_map<int, int> mp;
            mp[0] = -1;
            int diff = 0;
            int best = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] != c1 && s[i] != c2) {
                    // reset when third character appears
                    mp.clear();
                    mp[0] = i;
                    diff = 0;
                    continue;
                }

                if (s[i] == c1)
                    diff++;
                else
                    diff--;

                if (mp.count(diff))
                    best = max(best, i - mp[diff]);
                else
                    mp[diff] = i;
            }
            return best;
        };

        ans = max(
            {ans, solveTwo('a', 'b'), solveTwo('a', 'c'), solveTwo('b', 'c')});

        // Case 3: all three characters
        unordered_map<string, int> mp;
        mp["0#0"] = -1;

        int ca = 0, cb = 0, cc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a')
                ca++;
            if (s[i] == 'b')
                cb++;
            if (s[i] == 'c')
                cc++;

            int x = cb - ca;
            int y = cc - ca;

            string key = to_string(x) + "#" + to_string(y);

            if (mp.count(key))
                ans = max(ans, i - mp[key]);
            else
                mp[key] = i;
        }

        return ans;
    }
};
