//https://leetcode.cn/problems/flatten-a-multilevel-doubly-linked-list/submissions/548805043/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        process(head);
        return head;
    }
    Node* process(Node* head) {
        Node* cur = head, * nex, * pre;
        while (cur) {
            nex = cur->next;
            if (cur->child) {
                cur->next = cur->child;
                cur->child->prev = cur;
                Node* chi = cur->child;
                cur->child = nullptr;
                cur = process(chi);
                cur->next = nex;
                if (nex) {
                    nex->prev = cur;
                }
            }
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};