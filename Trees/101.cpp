// 101. Symmetric Tree

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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<string> temp;
            for(int i=0;i<size;i++) {
                TreeNode* top = q.front();
                if(top->left) {
                    temp.push_back(to_string(top->left->val));
                    q.push(top->left);
                }
                else {
                    temp.push_back("null");
                }
                if(top->right) {
                    temp.push_back(to_string(top->right->val));
                    q.push(top->right);
                }
                else {
                    temp.push_back("null");
                }
                q.pop();
            }
            for(int i=0,j=temp.size()-1;i<j;i++,j--) {
                if(temp[i]!=temp[j])
                    return false;
            }
        }
        return true;
    }
};