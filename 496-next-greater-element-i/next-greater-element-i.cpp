class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums2[st.top()] < nums2[i]){
                ans[st.top()] = nums2[i];
                st.pop();
            }
            st.push(i);
        }
        vector<int> r;
        for(int i = 0; i < nums1.size(); i++){
            int id = find(nums2.begin(), nums2.end(), nums1[i]) - nums2.begin();
            r.push_back(ans[id]);
        }
        return r;
    }
};