// 1008. Construct Binary Search Tree from Preorder Traversal
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++) {
            root = formBST(root, preorder[i]);
        }
        return root;
    }
private:
    TreeNode* formBST(TreeNode* root, int val) {
        if(!root) {
            TreeNode* temp = new TreeNode(val);
            return temp;
        }
        else if(root->val<val) {
            root->right = formBST(root->right, val);
        }
        else {
            root->left = formBST(root->left, val);
        }
        return root;
    }
};