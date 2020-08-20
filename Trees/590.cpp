// 590. N-ary Tree Postorder Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }
private:
    void postorder(Node* root, vector<int> &res) {
        if(!root)
            return;
        for(auto node:root->children){
            postorder(node, res);
        }
        res.push_back(root->val);
    }
};