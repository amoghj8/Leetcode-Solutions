// 783. Minimum Distance Between BST Nodes

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
    int minDiffInBST(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        int minVal = INT_MAX;
        for(int i=0;i<result.size()-1;i++)  {
         for(int j=i+1;j<result.size();j++) {
             if(result[j]-result[i]< minVal)
                 minVal = result[j]-result[i];
         }   
        }
        return minVal;
    }
private:
    void helper(TreeNode* root, vector<int> &result) {
        if(!root)
            return;
        helper(root->left,result);
        result.push_back(root->val);
        helper(root->right,result);
        return;
    }
};