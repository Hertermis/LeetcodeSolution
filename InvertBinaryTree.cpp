//https://leetcode.cn/problems/invert-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        process(root);
        return root;
    }
    void process(TreeNode* root) {
        if (!root) {
            return;
        }
        //swap
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        process(root->left);
        process(root->right);
    }
};