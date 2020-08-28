//404. Sum of Left Leaves

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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        int count = 0;
        helper(root, count, false);
        return count;
    }
private:
    void helper(TreeNode* root, int &count, bool isLeft) {
        if(!root->left && !root->right) {
            if(isLeft)
                count+=root->val;
            return;
        }
        if(root->left)
            helper(root->left, count, true);
        if(root->right)
            helper(root->right, count, false);
        return;
     }
};