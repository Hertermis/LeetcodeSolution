//https://leetcode.cn/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* cur;
        int size = 1;
        while (!q.empty()) {
            vector<int> tmp;
            size = q.size();
            while (size--) {
                cur = q.front();
                tmp.emplace_back(cur->val);
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};