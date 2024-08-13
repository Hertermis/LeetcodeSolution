//https://leetcode.cn/problems/first-common-ancestor-lcci/
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
    struct Info {
        TreeNode* ans;
        bool find_p;
        bool find_q;
        Info(TreeNode* a, bool p, bool q) : ans(a), find_p(p), find_q(q) {};
    };

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Info rec = process(root, p, q);
        return rec.ans;
    }
    Info process(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return Info(nullptr, false, false);
        }
        Info left = process(root->left, p, q);
        Info right = process(root->right, p, q);
        TreeNode* a = nullptr;
        bool fp = false;
        bool fq = false;
        if (left.find_p || root == p || right.find_p) {
            fp = true;
        }
        if (left.find_q || root == q || right.find_q) {
            fq = true;
        }
        if (left.ans) {
            a = left.ans;
        }
        if (right.ans) {
            a = right.ans;
        }
        if (a == nullptr) {
            if (fp && fq) {
                a = root;
            }
        }
        return Info(a, fp, fq);
    }
};