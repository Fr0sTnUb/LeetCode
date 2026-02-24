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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;
        q.push(root);
        bool dir = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> res(size);
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                // res.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(dir) res[i] = node->val;
                else res[size-i-1]= node->val;
            }
            ans.push_back(res);
            dir=!dir;
        }
        return ans;
    }
};  