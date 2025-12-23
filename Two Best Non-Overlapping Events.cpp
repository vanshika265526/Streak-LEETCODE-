/*
You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. 
The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei.
You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and 
the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.


  */

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        // Sort events by end time
        sort(events.begin(), events.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> endTimes(n);
        vector<int> maxValueTill(n);

        for (int i = 0; i < n; i++) {
            endTimes[i] = events[i][1];
        }

        maxValueTill[0] = events[0][2];
        for (int i = 1; i < n; i++) {
            maxValueTill[i] = max(maxValueTill[i - 1], events[i][2]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int value = events[i][2];

            // Take this event alone
            ans = max(ans, value);

            // Find last event that ends < start
            int idx = lower_bound(endTimes.begin(), endTimes.end(), start) - endTimes.begin() - 1;

            if (idx >= 0) {
                ans = max(ans, value + maxValueTill[idx]);
            }
        }

        return ans;
    }
};
