// 5532. Even Odd Tree

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            bool checkForOdd = false;
            if(!(level&1))
                checkForOdd = true;
            
            vector<int> levelElements;
            while(size--) {
                
                TreeNode* top = q.front();
                levelElements.push_back(top->val);
                q.pop();
                
                if(checkForOdd) {
                    if(!(top->val&1))
                        return false;
                }
                else {
                    if(top->val&1)
                        return false;
                }
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
             }
            if(checkForOdd) {
                for(int i=1;i<levelElements.size();i++) {
                    if(levelElements[i]<=levelElements[i-1])
                        return false;
                }
            }
            else {
                for(int i=1;i<levelElements.size();i++) {
                    if(levelElements[i]>=levelElements[i-1])
                        return false;
                }
            }
            level++;
        }
        return true;
    }
};