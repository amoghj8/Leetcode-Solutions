// 98. Validate Binary Search Tree

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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return isBSTUtil(root, LONG_MAX, LONG_MIN) ; 
    }
private:
    bool isBSTUtil(TreeNode* root, long maxValue, long minValue) {
        if(!root)
            return true;
        if(root->val<maxValue && root->val>minValue) {
            if(isBSTUtil(root->left, root->val, minValue) && isBSTUtil(root->right, maxValue, root->val))
                return true;
            else 
                return false;
        }
        return false;
        
    }
};