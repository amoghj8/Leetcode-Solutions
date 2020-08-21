// 637. Average of Levels in Binary Tree

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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)
            return {};
        vector<double> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            long sum = 0;
            for(int i=0;i<size;i++) {
                TreeNode *top= q.front();
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                q.pop();
                sum +=top->val;
            }
            result.push_back((double)sum/size);
        }
        return result;
    }
};