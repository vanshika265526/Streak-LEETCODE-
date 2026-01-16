class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const long long MOD = 1e9 + 7;

        // add boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<long long> horizontalDiffs;

        // all possible horizontal differences
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                horizontalDiffs.insert(hFences[j] - hFences[i]);
            }
        }

        long long maxSide = -1;

        // check vertical differences
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                long long diff = vFences[j] - vFences[i];
                if (horizontalDiffs.count(diff)) {
                    maxSide = max(maxSide, diff);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (maxSide * maxSide) % MOD;
    }
};
