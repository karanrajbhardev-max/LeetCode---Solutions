class Solution {
private:
    vector<int> computeLPS(string s) {
        int n = s.size();
        vector<int> LPS(n, 0);
        int j = 0;
        int i = 1;
        
        while (i < n) {
            if (s[i] == s[j]) {
                LPS[i] = j + 1;
                i++;
                j++;
            } else {
                while (j > 0 && s[i] != s[j]) {
                    j = LPS[j - 1];
                }
                if (s[i] == s[j]) {
                    LPS[i] = j + 1;
                    j++;
                }
                i += 1;
            }
        }
        return LPS;
    }

public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string combined = strs[0];
        for (int i = 1; i < strs.size(); i++) {
           
            combined += "#" + strs[i]; 
        }
       
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i == strs[j].length() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};