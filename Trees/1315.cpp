//1315. Sum of Nodes with Even-Valued Grandparent

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
    int sumEvenGrandparent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int sum = 0;
        while(!q.empty()) {
            int size  = q.size();
            
            for(int i=0;i<size;i++) {
                TreeNode* top = q.front();
                if(top->left) {
                    q.push(top->left);
                    if(!(top->val & 1))  {
                        sum+= top->left->left ? top->left->left->val : 0;
                        sum+= top->left->right ? top->left->right->val : 0;
                    }
                }
                if(top->right) {
                    q.push(top->right);
                    if(!(top->val & 1))  {
                        sum+= top->right->left ? top->right->left->val : 0;
                        sum+= top->right->right ? top->right->right->val : 0;
                    }
                }
                q.pop();
            }
        }
        return sum;
    }
};