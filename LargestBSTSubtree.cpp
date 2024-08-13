//https://leetcode.cn/problems/largest-bst-subtree/description/
class Solution {
    struct Info {
        bool is_searchTree;
        int size;
        int min;
        int max;
        Info(int val) :is_searchTree(true), size(0), min(val), max(val) {};
        Info(bool is, int s, int mi, int ma) :is_searchTree(is), size(s), min(mi), max(ma) {}
    };
public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        unique_ptr<Info> ans = process(root);
        return ans->size;
    }

    unique_ptr<Info> process(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        unique_ptr<Info> left = process(root->left);
        unique_ptr<Info> right = process(root->right);
        int min = root->val;
        int max = root->val;
        if (left) {
            min = min < left->min ? min : left->min;
            max = max > left->max ? max : left->max;
        }
        if (right) {
            min = min < right->min ? min : right->min;
            max = max > right->max ? max : right->max;
        }
        bool is_BST = false;
        int size = 0;
        if ((!left || (left->is_searchTree && left->max < root->val))
            && (!right || (right->is_searchTree && right->min > root->val))) {
            is_BST = true;
            if (left) {
                size += left->size;
            }
            if (right) {
                size += right->size;
            }
            size++;
        }
        else {
            if (left) {
                size = left->size;
            }
            if (right) {
                size = size > right->size ? size : right->size;
            }
        }
        unique_ptr<Info> ret = make_unique<Info>(is_BST, size, min, max);
        return ret;
    }
};