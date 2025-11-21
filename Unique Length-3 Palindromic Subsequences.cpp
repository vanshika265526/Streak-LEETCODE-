/*
Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

A palindrome is a string that reads the same forwards and backwards.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
  */

int countPalindromicSubsequence(string s) {
    int n = s.size();
    set<string> palindromes;

    // checking each possible first last letter
    for (char c = 'a'; c <= 'z'; c++) {
        
        int first = -1, last = -1;

        // finding first and last  of c
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                if (first == -1) first = i;
                last = i;
            }
        }

        //  occurs < 2 times
        if (first == -1 || first == last) continue;

        //  all middle characters
        set<char> midChars;
        for (int i = first + 1; i < last; i++) {
            midChars.insert(s[i]);
        }

        // form palindrome c mid c
        for (char mid : midChars) {
            string p = "";
            p += c;
            p += mid;
            p += c;
            palindromes.insert(p);
        }
    }

    return palindromes.size();
}
