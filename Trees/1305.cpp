// 1305. All Elements in Two Binary Search Trees

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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> result;
        if(root1)
            helper(root1, result);
        if(root2)
            helper(root2,result);
        sort(result.begin(),result.end());
        return result;
    }
private:
    void helper(TreeNode* root, vector<int>&ans) {
        if(!root) {
            return;
        }
        helper(root->left, ans);
        helper(root->right,ans);
        ans.push_back(root->val);
        return;
    }
};