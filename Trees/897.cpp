// 897. Increasing Order Search Tree

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
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> res;
        inorder(root, res);
        for(int i=0;i<res.size()-1;i++) {
            res[i]->left = nullptr;
            res[i]->right = res[i+1];
        }
        res[res.size()-1]->right = res[res.size()-1]->left = nullptr;
        return res[0];
    }
private:
    void inorder(TreeNode* root, vector<TreeNode*> &res) {
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root);
        inorder(root->right, res);
    }
};