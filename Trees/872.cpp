// 872. Leaf-Similar Trees

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> first;
        vector<int> second;
        postOrder(root1, first);
        postOrder(root2, second);
        if(first.size()!=second.size())
            return false;
        for(int i=0;i<first.size();i++) {
            if(first[i]!=second[i])
                return false;
        }
        return true;
    }
private: 
    void postOrder(TreeNode* root, vector<int> &leafVec) {
        if(!root->left && !root->right){
            leafVec.push_back(root->val);
            return;
        }
        if(root->left)
            postOrder(root->left, leafVec);
        if(root->right)
            postOrder(root->right, leafVec);
    }
};