/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
*/
class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[py] = px;
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) { return a[2] < b[2]; });

        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unite(0, firstPerson);

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            vector<int> touched;

            int j = i;
            while (j < meetings.size() && meetings[j][2] == time) {
                unite(meetings[j][0], meetings[j][1]);
                touched.push_back(meetings[j][0]);
                touched.push_back(meetings[j][1]);
                j++;
            }

            // rollback those not connected to 0
            for (int person : touched) {
                if (find(person) != find(0)) {
                    parent[person] = person;
                }
            }

            i = j;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (find(i) == find(0))
                ans.push_back(i);
        }

        return ans;
    }
};
