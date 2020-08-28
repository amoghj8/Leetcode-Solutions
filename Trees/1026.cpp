// 1026. Maximum Difference Between Node and Ancestor

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
    int maxAncestorDiff(TreeNode* root) {
        int maxEle= root->val;
        int minEle = root->val;
        int total = 0;
        helper(root, maxEle, minEle, total);
        return total;
    }
private:
    void helper(TreeNode* root, int maxEle, int minEle, int &total) {
        
        if(root->val > maxEle) {
            maxEle = root->val;
        }
        if(root->val < minEle) {
            minEle = root->val;
        }
        
        if(!root->left && !root->right) {
            total = max(total, abs(maxEle - minEle));
            return;
        }
       
        if(root->left) {
            helper(root->left, maxEle, minEle, total);
        }
        
        if(root->right) {
            helper(root->right, maxEle, minEle, total);
        }
        
    }
};