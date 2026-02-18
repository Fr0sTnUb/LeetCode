class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n, -1);
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                ans[st.top()] = nums[i];
                st.pop();
            }
        }
        return ans;
    }
};