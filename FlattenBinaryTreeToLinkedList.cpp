//https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        process(root);
    }
    TreeNode* process(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        TreeNode* cur = root;
        TreeNode* cL = cur->left;
        TreeNode* cR = cur->right;
        cur->left = nullptr;
        if (cL) {
            cur->right = cL;
            cur = process(cL);
        }
        if (cR) {
            cur->right = cR;
            cur = process(cR);
        }
        return cur;
    }
};
//Space:O(1)
//���ߣ����۹ٷ����
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while (curr != nullptr) {
            if (curr->left != nullptr) {
                auto next = curr->left;
                auto predecessor = next;
                while (predecessor->right != nullptr) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->left = nullptr;
                curr->right = next;
            }
            curr = curr->right;
        }
    }
};
