class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmall(n, n);
        vector<int> prevSmall(n, -1);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                prevSmall[i] = st.top();
            }
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nextSmall[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i<n; i++){
            int width = nextSmall[i] - prevSmall[i] - 1;
            int area = width * heights[i];
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};