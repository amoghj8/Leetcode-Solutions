// 107. Binary Tree Level Order Traversal II

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        result.push_back({root->val});
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++) {
                TreeNode* top = q.front();
                if(top->left) {
                    temp.push_back(top->left->val);
                    q.push(top->left);
                }
                if(top->right) {
                    temp.push_back(top->right->val);
                    q.push(top->right);
                }
                q.pop();
            }
            if(temp.size())
                result.insert(result.begin(),temp);
        }
        return result;
    }
};