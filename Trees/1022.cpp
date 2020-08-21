// 1022. Sum of Root To Leaf Binary Numbers

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
    int sumRootToLeaf(TreeNode* root) {
        if(!root->left && !root->right)
            return root->val;
        string start = "";
        vector<string> res;
        int total=0;
        addNos(root,start, total);
        return total;
    }
private:
    void addNos(TreeNode* root, string temp, int &total) {
        string tempStr = temp + to_string(root->val);
        if(!root->left && !root->right) {
            bitset<32> bset(tempStr);
            total+= bset.to_ulong();
            return;
        }
        if(root->left) {
            addNos(root->left, tempStr, total);
        }
        if(root->right) {
            addNos(root->right, tempStr, total);
        }
    }
};