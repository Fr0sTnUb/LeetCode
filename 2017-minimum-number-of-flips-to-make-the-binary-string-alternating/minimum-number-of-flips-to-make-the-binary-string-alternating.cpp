class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string alt1, alt2;
        
        for (int i = 0; i < 2 * n; i++) {
            alt1 += (i % 2 == 0) ? '0' : '1';
            alt2 += (i % 2 == 0) ? '1' : '0';
        }
        
        s += s;  // Double the string for circular simulation
        
        int flips1 = 0, flips2 = 0;
        int result = INT_MAX;
        
        for (int i = 0; i < 2 * n; i++) {
            if (s[i] != alt1[i]) flips1++;
            if (s[i] != alt2[i]) flips2++;
            
            if (i >= n) {
                if (s[i - n] != alt1[i - n]) flips1--;
                if (s[i - n] != alt2[i - n]) flips2--;
            }
            
            if (i >= n - 1) {
                result = min({result, flips1, flips2});
            }
        }
        
        return result;  // ✅ Must return result, not min(flips1, flips2)
    }
};