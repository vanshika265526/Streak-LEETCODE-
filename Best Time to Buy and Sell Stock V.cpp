/*
You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.


  */

class Solution {
public:
    int n;
    vector<int> p;
    long long dp[1005][505][2][2];
    
    long long solve(int i, int t, int open, int type, int k) {
        if (i == n || t == k) {
            return open ? LLONG_MIN / 2 : 0;
        }
        
        long long &ans = dp[i][t][open][type];
        if (ans != -1) return ans;
        
        ans = solve(i + 1, t, open, type, k); // do nothing
        
        if (!open) {
            // start normal transaction
            ans = max(ans, -p[i] + solve(i + 1, t, 1, 0, k));
            // start short transaction
            ans = max(ans, +p[i] + solve(i + 1, t, 1, 1, k));
        } else {
            if (type == 0) {
                // close normal transaction (sell)
                ans = max(ans, +p[i] + solve(i + 1, t + 1, 0, 0, k));
            } else {
                // close short transaction (buy back)
                ans = max(ans, -p[i] + solve(i + 1, t + 1, 0, 0, k));
            }
        }
        
        return ans;
    }
    
    long long maximumProfit(vector<int>& prices, int k) {
        p = prices;
        n = prices.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, 0, k);
    }
};
