//1448. Count Good Nodes in Binary Tree

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
    int goodNodes(TreeNode* root) {
        int result = 0;
        helper(root, result, INT_MIN);
        return result;
    }
private:
    void helper(TreeNode* root, int &total, int maxVal) {
        if(root->val >= maxVal) {
            maxVal = root->val;
            total++;
        }
        if(root->left)
            helper(root->left, total, maxVal);
        if(root->right)
            helper(root->right, total, maxVal);
    }
};