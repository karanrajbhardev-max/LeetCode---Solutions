class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int largestArea = 0;
        int area;

        stack<int> st;

        int nse, pse;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int ind = st.top();
                st.pop();

                pse = st.empty() ? -1 : st.top();
                nse = i;
                area = heights[ind] * (nse - pse - 1);
                largestArea = max(largestArea, area);
            }
            st.push(i);
        }

        while (!st.empty()) {
            nse = n;
            int ind = st.top();
            st.pop();

            pse = st.empty() ? -1 : st.top();
            area = heights[ind] * (nse - pse - 1);
            largestArea = max(largestArea, area);
        }
        return largestArea;
    }
};