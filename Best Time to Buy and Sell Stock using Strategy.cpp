/*
You are given two integer arrays prices and strategy, where:

prices[i] is the price of a given stock on the ith day.
strategy[i] represents a trading action on the ith day, where:
-1 indicates buying one unit of the stock.
0 indicates holding the stock.
1 indicates selling one unit of the stock.
You are also given an even integer k, and may perform at most one modification to strategy. A modification consists of:

Selecting exactly k consecutive elements in strategy.
Set the first k / 2 elements to 0 (hold).
Set the last k / 2 elements to 1 (sell).
The profit is defined as the sum of strategy[i] * prices[i] across all days.

Return the maximum possible profit you can achieve.

Note: There are no constraints on budget or stock ownership, so all buy and sell operations are feasible regardless of past actions.
*/

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        
        // Original profit
        long long baseProfit = 0;
        for (int i = 0; i < n; i++) {
            baseProfit += 1LL * strategy[i] * prices[i];
        }

        // Prefix sum of current contribution
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + 1LL * strategy[i] * prices[i];
        }

        // Prefix sum of prices
        vector<long long> pricePref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pricePref[i + 1] = pricePref[i] + prices[i];
        }

        long long maxDelta = 0;

        for (int i = 0; i + k <= n; i++) {
            int mid = i + k / 2;

            // First half becomes HOLD (0)
            long long firstHalfLoss =
                pref[mid] - pref[i];

            // Second half becomes SELL (1)
            long long secondHalfGain =
                (pricePref[i + k] - pricePref[mid]) -
                (pref[i + k] - pref[mid]);

            long long delta = -firstHalfLoss + secondHalfGain;
            maxDelta = max(maxDelta, delta);
        }

        return baseProfit + maxDelta;
    }
};
