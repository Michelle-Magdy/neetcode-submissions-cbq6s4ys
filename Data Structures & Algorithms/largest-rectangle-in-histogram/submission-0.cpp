class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next(n,n),prev(n,-1);
        stack<int> st;
         for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                prev[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = next[i] - prev[i] - 1;
            maxArea = max(maxArea, width * heights[i]);
        }

        return maxArea;
    }
};
