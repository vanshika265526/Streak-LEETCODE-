/*
You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.

Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.

Answers within 10-5 of the actual answer will be accepted.

Note: Squares may overlap. Overlapping areas should be counted only once in this version.


*/
class Solution {
public:
    struct Node {
        long long cover = 0;
        long long len = 0;
    };

    vector<long long> xs;
    vector<Node> seg;

    void update(int idx, int l, int r, int ql, int qr, int val) {
        if (qr <= l || r <= ql) return;
        if (ql <= l && r <= qr) {
            seg[idx].cover += val;
        } else {
            int mid = (l + r) >> 1;
            update(idx << 1, l, mid, ql, qr, val);
            update(idx << 1 | 1, mid, r, ql, qr, val);
        }

        if (seg[idx].cover > 0) {
            seg[idx].len = xs[r] - xs[l];
        } else if (l + 1 == r) {
            seg[idx].len = 0;
        } else {
            seg[idx].len = seg[idx << 1].len + seg[idx << 1 | 1].len;
        }
    }

    double separateSquares(vector<vector<int>>& squares) {
        vector<array<long long,4>> events; 
        xs.clear();

        for (auto &v : squares) {
            long long x = v[0], y = v[1], l = v[2];
            xs.push_back(x);
            xs.push_back(x + l);
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        int n = xs.size();
        seg.assign(4 * n, {0, 0});

        sort(events.begin(), events.end());

        long double total = 0;
        long double prevY = events[0][0];

        for (int i = 0; i < events.size(); ++i) {
            long double curY = events[i][0];
            total += (curY - prevY) * seg[1].len;
            prevY = curY;

            int l = lower_bound(xs.begin(), xs.end(), events[i][1]) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), events[i][2]) - xs.begin();
            update(1, 0, n - 1, l, r, events[i][3]);
        }

        long double half = total / 2.0;
        seg.assign(4 * n, {0, 0});

        long double curArea = 0;
        prevY = events[0][0];

        for (int i = 0; i < events.size(); ++i) {
            long double curY = events[i][0];
            long double width = seg[1].len;
            long double slab = (curY - prevY) * width;

            if (curArea + slab >= half) {
                long double need = half - curArea;
                long double dy = need / width;
                return double(prevY + dy);
            }

            curArea += slab;
            prevY = curY;

            int l = lower_bound(xs.begin(), xs.end(), events[i][1]) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), events[i][2]) - xs.begin();
            update(1, 0, n - 1, l, r, events[i][3]);
        }

        return prevY;
    }
};
