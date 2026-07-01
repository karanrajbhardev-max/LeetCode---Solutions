class Solution {
private:
    vector<int> zFunction(const string& s) {
        int n = s.length();
        vector<int> z(n, 0);
        int l = 0, r = 0;
        
        for (int i = 1; i < n; i++) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] - 1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0; 

        string combined = needle + "$" + haystack; 
        vector<int> z = zFunction(combined);
        
        int needleLen = needle.size();
        for (int i = needleLen + 1; i < (int)combined.size(); i++) {
            if (z[i] == needleLen) {
                return i - needleLen - 1; 
            }
        }
        
        return -1; 
    }
};