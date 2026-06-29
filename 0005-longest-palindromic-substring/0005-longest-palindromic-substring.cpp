class Solution {
private: 
    pair<int,int> expandAroundCenter(const string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return {left+1, right-1};
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0) return "";

        int start = 0, end = 0;

        for(int i = 0; i < n; i++){
            auto odd = expandAroundCenter(s,i,i);
            auto even = expandAroundCenter(s,i,i+1);

            if(odd.second - odd.first > end - start){
                start = odd.first;
                end = odd.second;
            }

            if(even.second - even.first > end - start){
                start = even.first;
                end = even.second;
            }
        }

        return s.substr(start, end-start+1);
        
    }
};