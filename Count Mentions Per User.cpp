/*
You are given an integer numberOfUsers representing the total number of users and an array events of size n x 3.

Each events[i] can be either of the following two types:

Message Event: ["MESSAGE", "timestampi", "mentions_stringi"]
This event indicates that a set of users was mentioned in a message at timestampi.
The mentions_stringi string can contain one of the following tokens:
id<number>: where <number> is an integer in range [0,numberOfUsers - 1]. There can be multiple ids separated by a single whitespace and may contain duplicates. This can mention even the offline users.
ALL: mentions all users.
HERE: mentions all online users.
Offline Event: ["OFFLINE", "timestampi", "idi"]
This event indicates that the user idi had become offline at timestampi for 60 time units. The user will automatically be online again at time timestampi + 60.
Return an array mentions where mentions[i] represents the number of mentions the user with id i has across all MESSAGE events.

All users are initially online, and if a user goes offline or comes back online, their status change is processed before handling any message event that occurs at the same timestamp.

Note that a user can be mentioned multiple times in a single message event, and each mention should be counted separately.

 

Example 1:

Input: numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]]

Output: [2,2]
  */

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        vector<bool> online(numberOfUsers, true);
        vector<int> offlineUntil(numberOfUsers, 0);

        // Convert timestamps + store type properly
        vector<tuple<int,string,string>> ev;
        for (auto &e : events) {
            int t = stoi(e[1]);
            ev.push_back({t, e[0], e[2]});
        }

        // Sort by time, but OFFLINE before MESSAGE when time ties
        sort(ev.begin(), ev.end(), [](auto &a, auto &b){
            if (get<0>(a) != get<0>(b))
                return get<0>(a) < get<0>(b);

            // same timestamp → OFFLINE first
            string A = get<1>(a);
            string B = get<1>(b);

            if (A == B) return false;
            return A == "OFFLINE"; 
        });

        for (auto &[time, type, info] : ev) {
            // Process users returning online
            for (int u = 0; u < numberOfUsers; u++) {
                if (!online[u] && offlineUntil[u] <= time) {
                    online[u] = true;
                }
            }

            if (type == "OFFLINE") {
                int id = stoi(info);
                online[id] = false;
                offlineUntil[id] = time + 60;
            }
            else { // MESSAGE
                if (info == "ALL") {
                    for (int u = 0; u < numberOfUsers; u++) mentions[u]++;
                }
                else if (info == "HERE") {
                    for (int u = 0; u < numberOfUsers; u++) {
                        if (online[u]) mentions[u]++;
                    }
                }
                else {
                    // explicit id mentions
                    stringstream ss(info);
                    string token;
                    while (ss >> token) {
                        int id = stoi(token.substr(2));
                        mentions[id]++;
                    }
                }
            }
        }

        return mentions;
    }
};
