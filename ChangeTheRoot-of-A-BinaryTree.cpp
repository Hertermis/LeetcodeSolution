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
        //�Ͽ���ǰ�ڵ�͸��ڵ����ϵ
        if (parent) {
            if (cur == parent->left)
                parent->left = nullptr;
            else
                parent->right = nullptr;

            cur->parent = nullptr;
        }
        //�ݹ��ȥȫ������ϡ���ǰ�ڵ�͸��ڵ����ϵ
        flip(parent);
        //flipת�����ӹ�ϵ��������װ
        if (parent) {
            if (cur->left)//�����������Ҫ�������ƶ����Һ��ӵ�λ���ϱ���
                cur->right = cur->left;
            cur->left = parent;
            parent->parent = cur;
        }
    }
};