//https://leetcode.cn/problems/binary-tree-postorder-traversal/
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root) {
            stack<TreeNode*> s;
            s.push(root);
            TreeNode* cur = root, * rec;
            while (!s.empty()) {
                rec = s.top();
                if (rec->left && cur != rec->left && cur != rec->right) {
                    s.push(rec->left);
                }
                else if (rec->right && cur != rec->right) {
                    s.push(rec->right);
                }
                else {
                    ans.emplace_back(s.top()->val);
                    s.pop();
                    cur = rec;
                }
            }
        }
        return ans;
    }
};