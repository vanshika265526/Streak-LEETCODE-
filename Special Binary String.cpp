class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> res;
        int count = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            if (count == 0) {
                // valid substring
                string inner = s.substr(start + 1, i - start - 1);
                string processed = "1" + makeLargestSpecial(inner) + "0";
                res.push_back(processed);
                start = i + 1;
            }
        }

        // sort in descending order
        sort(res.begin(), res.end(), greater<string>());

        // join
        string result = "";
        for (auto &str : res) result += str;

        return result;
    }
};
