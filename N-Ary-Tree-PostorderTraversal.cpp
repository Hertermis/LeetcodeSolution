//https://leetcode.cn/problems/n-ary-tree-postorder-traversal/
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
//Recursive
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        pos(ans,root);
        return ans;
    }
    void pos(vector<int>& nums,Node* root){
        if(!root){
            return;
        }
        for(int i=0;i<root->children.size();i++){
            pos(nums,root->children[i]);
        }
        nums.emplace_back(root->val);
    }
};
//Iterative
class Solution {
public:
    vector<int> postorder(Node* root) {
        unordered_map<Node*, bool> use;
        vector<int> ans;
        if (!root) {
            return ans;
        }
        Node* cur = root;
        stack<Node*>s;
        s.push(cur);
        use.insert(make_pair(cur, false));
        while (!s.empty()) {
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                use.insert(make_pair(cur->children[i], false));
                if (use[cur->children[i]] == false) {
                    s.push(cur->children[i]);
                }
            }
            Node* tmp = s.top();
            if (tmp != cur) {
                cur = tmp;
                continue;
            }
            else {
                ans.emplace_back(tmp->val);
                use[tmp] = true;
                s.pop();
            }
        }
        return ans;
    }

};
