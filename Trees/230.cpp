//230. Kth Smallest Element in a BST

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> result;
        helper(root,result);
        return result[k-1];
    }
private:
    void helper(TreeNode* root, vector<int>&res) {
        if(!root)
            return;
        helper(root->left,res);
        res.push_back(root->val);
        helper(root->right,res);
    }
};