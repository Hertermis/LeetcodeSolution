//https://leetcode.cn/problems/n-ary-tree-level-order-traversal/description/
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        Node* cur;
        int size = 1;
        while (!q.empty()) {
            vector<int> tmp;
            size = q.size();
            while (size--) {
                cur = q.front();
                tmp.emplace_back(cur->val);
                q.pop();
                for (int i = 0; i < cur->children.size(); i++) {
                    q.push(cur->children[i]);
                }
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};