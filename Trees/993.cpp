// 993. Cousins in Binary Tree

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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int> m;
        while(!q.empty()) {
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++) {
                temp.push_back(q.front()->val);
                if(q.front()->left){
                    q.push(q.front()->left);
                    m[q.front()->left->val] = q.front()->val;
                }
                if(q.front()->right) {
                    m[q.front()->right->val] = q.front()->val;
                    q.push(q.front()->right);  
                }
                q.pop();
            }
            vector<int>:: iterator it1,it2;
            it1 = find(temp.begin(), temp.end(), x);
            it2 = find(temp.begin(), temp.end(), y);            
            if(it1!=temp.end() && it2!=temp.end()) {
                return m[x]!=m[y];
            }
            else if(it1==temp.end() && it2!=temp.end())
                return false;
            else if(it2==temp.end() && it1!=temp.end())
                return false;
        }
        return false;
    }
};