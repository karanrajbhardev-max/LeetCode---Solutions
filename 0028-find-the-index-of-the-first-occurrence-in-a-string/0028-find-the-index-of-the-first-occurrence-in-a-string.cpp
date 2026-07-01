class Solution {
private:
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);

        int i = 1, j = 0;
        while (i < n) {
            if (s[i] == s[j]) {
                LPS[i] = j + 1;
                j++, i++;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = LPS[j - 1];
                }
                if (s[i] == s[j]) {
                    LPS[i] = j + 1;
                    j++;
                }
                i = i + 1;
            }
        }
        return LPS;
    }

public:
    int strStr(string haystack, string needle) {
        string s = needle + '$' + haystack;
        vector<int> LPS = computeLPS(s);

        int n = needle.size(), m = haystack.size();

        for (int i = n + 1; i < s.size(); i++) {
            if (LPS[i] == n) {
                return (i - n - 1) - n + 1;
            }
        }

        return -1;
    }
};