class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> t_freq;
        for (char c : t) {
            t_freq[c]++;
        }
        
        int required = t_freq.size();
        int formed = 0;
        unordered_map<char, int> window_counts;
        
        int left = 0, right = 0;
        int min_len = INT_MAX;
        int min_left = 0;
        
        while (right < s.size()) {
            char c = s[right];
            window_counts[c]++;
            
            if (t_freq.count(c) && window_counts[c] == t_freq[c]) {
                formed++;
            }
            
            while (left <= right && formed == required) {
                c = s[left];
                
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    min_left = left;
                }
                
                window_counts[c]--;
                if (t_freq.count(c) && window_counts[c] < t_freq[c]) {
                    formed--;
                }
                
                left++;
            }
            
            right++;
        }
        
        return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
    }
};