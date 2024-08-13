//https://leetcode.cn/problems/swap-nodes-in-pairs/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* p = head, * q = head->next, * pre = nullptr;
        head = head->next;
        while (p && q) {
            p->next = q->next;
            q->next = p;
            if (pre) {
                pre->next = q;
            }
            pre = p;
            p = p->next;
            if (p) {
                q = p->next;
            }
        }
        return head;
    }
};