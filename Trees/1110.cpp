//1110. Delete Nodes And Return Forest

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        result.push_back(root);
        for(auto val:to_delete) {
            helper(result, val);
        }
        set<TreeNode*> s;
        for(auto nodeVal: to_delete) {
            for(int i=0;i<result.size();i++) {
                if(nodeVal == result[i]->val) {
                    result.erase(result.begin()+i);
                    i--;
                }
            }
        }
        for(auto node: result) {
            s.insert(node);
        }
        result.clear();
        set<TreeNode*>::iterator it;
        for(it=s.begin();it!=s.end();it++) {
            result.push_back(*it);
        }
        return result;
    }
private:
    void helper(vector<TreeNode*> &result, int val) {
        for(int i=0;i<result.size();i++) {
            deleteVal(result[i],val,result);
        }
    }
    
    TreeNode* deleteVal(TreeNode* root, int val, vector<TreeNode*> &result) {
        if(!root)
            return nullptr;
        if(root->val==val) {
            if(!root->left && !root->right)
                return nullptr;
            if(root->left) {
                result.push_back(root->left);
            }
            if(root->right) {
                result.push_back(root->right);
            }
            return nullptr;
        }
        if(root->right)
            root->right = deleteVal(root->right, val, result);
        if(root->left)
            root->left = deleteVal(root->left,val, result);
        return root;
    }
};