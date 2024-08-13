//https://leetcode.cn/problems/reorder-list/description/
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }
        ListNode* slow = head, * fast = head;
        //find middle
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast->next) {
            fast = fast->next;
        }
        //reverse slow-fast
        ListNode* pre = nullptr, * cur = slow->next, * nex;
        while (cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        slow->next = nullptr;
        //reorder
        cur = head;
        nex = head->next;
        while (pre) {
            cur->next = pre;
            cur = cur->next;
            pre = nex;
            nex = cur->next;
        }
        return;
    }
};