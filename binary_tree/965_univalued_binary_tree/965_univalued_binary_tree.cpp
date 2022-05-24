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
    bool dfs(TreeNode* node, int val) {
        if(!node) return true;
        if(node->val != val) return false;
        return dfs(node->left, val) && dfs(node->right, val);
    }
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        return dfs(root, root->val);
    }
};