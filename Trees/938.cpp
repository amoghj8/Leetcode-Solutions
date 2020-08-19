// 938. Range Sum of BST

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

// Method 1 : 

class Solution {
public:
    void inorder(TreeNode *root, int &sum,int L, int R) {
        if(!root)
            return;
        inorder(root->left, sum, L, R);
        if((root->val>=L) && (root->val<=R))
            sum+=root->val;
        inorder(root->right, sum, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = 0;
        inorder(root, sum, L, R);
        return sum;
    }
    
};

// Method 2 :

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
    void inorder(TreeNode *root,vector<int>& res) {
        if(!root)
            return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> result;
        int sum = 0;
        inorder(root, result);
        vector<int>::iterator it1,it2;
        it1= find(result.begin(),result.end(),L);
        it2= find(result.begin(),result.end(),R);
        
        for(int i=it1-result.begin();i<=it2-result.begin();i++) {
            sum+=result[i];
        }
        return sum;
    }
    
};