//https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/description/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        bool flag = 0;
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        q.emplace(root);
        TreeNode* cur;
        while (!q.empty()) {
            vector<int> tmp;
            flag = !flag;
            while (!q.empty()) {
                cur = q.front();
                q.pop();
                if (flag) {
                    tmp.emplace_back(cur->val);
                    if (cur->left) {
                        s.emplace(cur->left);
                    }
                    if (cur->right) {
                        s.emplace(cur->right);
                    }

                }
                else {
                    tmp.emplace_back(cur->val);
                    if (cur->right) {
                        s.emplace(cur->right);
                    }
                    if (cur->left) {
                        s.emplace(cur->left);
                    }
                }
            }
            while (!s.empty()) {
                cur = s.top();
                s.pop();
                q.emplace(cur);
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};