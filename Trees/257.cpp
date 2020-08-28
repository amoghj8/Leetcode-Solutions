//257. Binary Tree Paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string> result;
        helper(root, result, "");
        return result;
    }
private:
    void helper(TreeNode* root, vector<string> &result, string s) {
        if(!root->left && !root->right) {
            s+=to_string(root->val);
            result.push_back(s);
            return;
        }
        s+=to_string(root->val)+"->";
        if(root->left)
            helper(root->left, result, s);
        if(root->right)
            helper(root->right, result, s);
    }
};