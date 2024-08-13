//https://leetcode.cn/problems/SLwz0R/description/
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, * fast = head, * pre = nullptr;
        while (--n) {
            fast = fast->next;
        }
        while (fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next;
        }
        if (pre == nullptr) {
            return head->next;
        }
        pre->next = slow->next;
        return head;
    }
};