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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode;
        auto iterator = max_element(nums.begin(), nums.end());
        root->val = *iterator;
        vector<int> leftVec, rightVec;
        for(auto it=nums.begin();it!=iterator;it++) {
            leftVec.push_back(*it);
        }
        for(auto it=iterator+1;it!=nums.end();it++) {
            rightVec.push_back(*it);
        }
        root->left = formMaxBinTree(leftVec);
        root->right = formMaxBinTree(rightVec);
        return root;        
    }
private:
    TreeNode* formMaxBinTree(vector<int> &remVec) {
        if(!remVec.size())
            return nullptr;
        TreeNode* root = new TreeNode;
        auto iterator = max_element(remVec.begin(), remVec.end());
        root->val = *iterator;
        vector<int> leftVec, rightVec;
        for(auto it=remVec.begin();it!=iterator;it++) {
            leftVec.push_back(*it);
        }
        for(auto it=iterator+1;it!=remVec.end();it++) {
            rightVec.push_back(*it);
        }
        root->left = formMaxBinTree(leftVec);
        root->right = formMaxBinTree(rightVec);
        return root;        
    }
};