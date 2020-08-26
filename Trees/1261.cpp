//1305. All Elements in Two Binary Search Trees

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
class FindElements {
    TreeNode* temp;
private:
    void helper(TreeNode* root, int val) {
        root->val = val;
        if(root->left)
            helper(root->left, 2*val+1);
        if(root->right)
            helper(root->right, 2*val+2);
        return;
    }
    
    bool check(TreeNode* temp, int target) {
        if(!temp)
            return false;
        if(temp->val==target)
            return true;
        return check(temp->left, target) || check(temp->right,target);
    }
    
    
public:
    FindElements(TreeNode* root) {
        temp = root;
        helper(root,0);
    }
    
    bool find(int target) {
        return check(temp, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */