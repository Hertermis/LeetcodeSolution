//https://leetcode.cn/problems/copy-list-with-random-pointer/submissions/546754445/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }
        // rebuild
        Node* cur = head, * nex = nullptr;
        while (cur) {
            nex = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = nex;
            cur = nex;
        }
        // copy random
        cur = head;
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // split
        cur = head, nex = head->next;
        Node* ret = head->next;
        while (nex->next) {
            cur->next = nex->next;
            cur = nex->next;
            nex->next = cur->next;
            nex = cur->next;
        }
        cur->next = nullptr;
        nex->next = nullptr;
        return ret;
    }
};