class Solution {
public:
    void generate(vector<string> &ans, string s, int open, int close){
    if ( open == 0 && close == 0){
        ans.push_back(s);
        return;
    }
    if ( open > 0){
        generate(ans, s + '(', open - 1, close);
    }
    if ( close > open){
        generate(ans, s + ')', open, close - 1);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";
        generate(ans, s, n, n );
        return ans;
    }
};