//   Convert Sorted Array to Binary Search Tree


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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = helper(nums, 0, nums.size()-1);
        return root;
    }
private:
    TreeNode* getNewNode(int data) {
        TreeNode* temp = new TreeNode(data);
        return temp;
    }
    
    TreeNode* helper(vector<int>&nums, int low, int high) {
        if(low>high)
            return nullptr;
        
        int mid = low + (high-low)/2; 
        TreeNode *newNode = getNewNode(nums[mid]);
        
        newNode->left = helper(nums,low, mid-1);
        newNode->right = helper(nums, mid+1, high);
        
        return newNode;
            
    }
};