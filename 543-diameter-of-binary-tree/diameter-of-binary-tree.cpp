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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return -1;
        int diameter = 0;
        depth(root, diameter);
        return diameter;
    }
    int depth(TreeNode* node, int& diameter){
        if(!node) return 0;
        int lh =depth(node->left, diameter);
        int rh = depth(node->right, diameter);
        diameter = max(diameter, lh + rh);
        return max(lh, rh)+1;
    }
};