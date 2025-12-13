/*
You are given three arrays of length n that describe the properties of n coupons: code, businessLine, and isActive. The ith coupon has:

code[i]: a string representing the coupon identifier.
businessLine[i]: a string denoting the business category of the coupon.
isActive[i]: a boolean indicating whether the coupon is currently active.
A coupon is considered valid if all of the following conditions hold:

code[i] is non-empty and consists only of alphanumeric characters (a-z, A-Z, 0-9) and underscores (_).
businessLine[i] is one of the following four categories: "electronics", "grocery", "pharmacy", "restaurant".
isActive[i] is true.
Return an array of the codes of all valid coupons, sorted first by their businessLine in the order: "electronics", "grocery", "pharmacy", "restaurant", and then by code in lexicographical (ascending) order within each category.

 

Example 1:

Input: code = ["SAVE20","","PHARMA5","SAVE@20"], businessLine = ["restaurant","grocery","pharmacy","restaurant"], isActive = [true,true,true,true]

Output: ["PHARMA5","SAVE20"]

Explanation:

First coupon is valid.
Second coupon has empty code (invalid).
Third coupon is valid.
Fourth coupon has special character @ (invalid).
Example 2:

Input: code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true]

Output: ["ELECTRONICS_50"]
  */

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, 
                                   vector<string>& businessLine, 
                                   vector<bool>& isActive) {
        
        unordered_map<string, int> order = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };

        vector<pair<int, string>> valid;

        for (int i = 0; i < code.size(); i++) {
            // active check
            if (!isActive[i]) continue;

            // business line check
            if (order.find(businessLine[i]) == order.end()) continue;

            // code non-empty
            if (code[i].empty()) continue;

            // code character validation
            bool ok = true;
            for (char ch : code[i]) {
                if (!isalnum(ch) && ch != '_') {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            valid.push_back({order[businessLine[i]], code[i]});
        }

        sort(valid.begin(), valid.end());

        vector<string> result;
        for (auto& p : valid) {
            result.push_back(p.second);
        }

        return result;
    }
};
