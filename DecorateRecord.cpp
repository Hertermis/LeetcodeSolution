//https://leetcode.cn/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/description/
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
    vector<int> decorateRecord(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> q;
        q.emplace(root);
        int size;
        TreeNode* cur;
        while (!q.empty()) {
            size = q.size();
            while (size--) {
                cur = q.front();
                ans.emplace_back(cur->val);
                q.pop();
                if (cur->left) {
                    q.emplace(cur->left);
                }
                if (cur->right) {
                    q.emplace(cur->right);
                }
            }
        }
        return ans;
    }
};