// 965. Univalued Binary Tree

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
    bool isUnivalTree(TreeNode* root) {
        if(!root->left && !root->right)
            return true;
        int find = root->val;
        return checkTree(root, find);
    }
private: 
    bool checkTree(TreeNode* root, int val) {
        if(!root)
            return true;
        if(root->val !=val)
            return false;
        if(root->left) {
            return checkTree(root->left,val);
        }
        if(root->right) {
            return checkTree(root->right,val);
        } 
        return true;
    }
};