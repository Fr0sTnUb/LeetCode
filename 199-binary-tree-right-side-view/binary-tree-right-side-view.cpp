/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> lO;
        if(!root) return {};
        q.push(root);
        while(!q.empty()){
            vector<int> res;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                res.push_back(node->val);
            }
            lO.push_back(res);
        }
        vector<int> rsV;
        for(int i = 0; i < lO.size(); i++){
            rsV.push_back(lO[i][lO[i].size() - 1]);
        }
        return rsV;
    }
};