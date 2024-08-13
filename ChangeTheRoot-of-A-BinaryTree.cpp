//https://leetcode.cn/problems/change-the-root-of-a-binary-tree/
class Solution {
public:
    Node* flipBinaryTree(Node* root, Node* leaf) {
        flip(leaf);
        return leaf;
    }
    void flip(Node* cur) {
        if (cur == nullptr) return;
        Node* parent = cur->parent;
        //断开当前节点和父节点的联系
        if (parent) {
            if (cur == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            cur->parent = nullptr;
        }
        //递归地去全部“打断”当前节点和父节点的联系
        flip(parent);
        //flip转换父子关系，重新组装
        if (parent) {
            if (cur->left)//如果有左孩子需要保留，移动到右孩子的位置上保存
                cur->right = cur->left;
            cur->left = parent;
            parent->parent = cur;
        }
    }
};