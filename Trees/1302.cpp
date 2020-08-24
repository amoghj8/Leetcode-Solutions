// 1302. Deepest Leaves Sum

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int depth = 0;
        map<int, vector<int>> m;
        leafSum(root, depth, m);
        sum = accumulate(m.rbegin()->second.begin(), m.rbegin()->second.end(), sum);
        return sum;
    }
private:
    void leafSum(TreeNode* root, int depth, map<int, vector<int>>& m) {
        if(!root->left && !root->right) {
            m[depth].push_back(root->val);
            return;
        }
        if(root->left)
            leafSum(root->left, depth+1, m);
        if(root->right)
            leafSum(root->right, depth+1, m);
    }
};