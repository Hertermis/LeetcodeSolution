//https://leetcode.cn/problems/maximum-binary-tree/submissions/550991268/
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = process(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode* process(vector<int>& nums, int left, int right) {
        TreeNode* ret = nullptr;
        if (left <= right) {
            int index = left;
            for (int i = left; i <= right; i++) {
                index = nums[index] > nums[i] ? index : i;
            }
            ret = new TreeNode(nums[index]);
            ret->left = process(nums, left, index - 1);
            ret->right = process(nums, index + 1, right);
        }
        return ret;
    }
};