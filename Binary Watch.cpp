class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n) {
            count += (n & 1);
            n >>= 1;
        }
        return count;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countBits(h) + countBits(m) == turnedOn) {
                    
                    string time = to_string(h) + ":";
                    
                    if (m < 10) time += "0";  // ensure 2-digit minute
                    
                    time += to_string(m);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};
