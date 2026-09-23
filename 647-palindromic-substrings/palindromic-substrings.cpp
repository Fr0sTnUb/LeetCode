class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int c = 0; c < 2*n-1; ++c){
            int left = c/2;
            int right = left + c % 2;

            while(left >= 0 && right < n && s[left] == s[right]){
                ++count;
                --left;
                ++right;
            }
        }
        return count;
    }
};