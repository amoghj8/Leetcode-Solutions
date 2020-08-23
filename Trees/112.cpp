// 112. Path Sum

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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        bool flag = false;
        checkSum(root, sum, root->val, &flag);
        return flag;
    }
private:
    void checkSum(TreeNode* root, int sum, int tempSum, bool *flag) {
       if(!root->left && !root->right){
            if(tempSum == sum) {
                *flag = true;
            }
            return;
        }
        if(root->left)
            checkSum(root->left, sum, tempSum+root->left->val, flag);
        if(root->right)
            checkSum(root->right, sum, tempSum+root->right->val, flag);
    }
};