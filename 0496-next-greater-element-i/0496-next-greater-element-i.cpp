class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next_greater;
        stack<int> st;
    
        for (int i = nums2.size() - 1; i >= 0; i--) {
            int currEle = nums2[i];
            
            while (!st.empty() && st.top() <= currEle) {
                st.pop();
            }
            
            if (st.empty()) {
                next_greater[currEle] = -1;
            } else {
                next_greater[currEle] = st.top();
            }
            
            st.push(currEle);
        }
        
        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = next_greater[nums1[i]];
        }
        
        return ans;
    }
};