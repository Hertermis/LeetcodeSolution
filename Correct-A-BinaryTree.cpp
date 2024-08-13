//https://leetcode.cn/problems/correct-a-binary-tree/description/
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
    unordered_set<TreeNode*> visited;
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (!root || (root->right && visited.find(root->right) != visited.end())) {
            return nullptr;
        }
        visited.insert(root);
        root->right = correctBinaryTree(root->right);
        root->left = correctBinaryTree(root->left);
        return root;
    }
};