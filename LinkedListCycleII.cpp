//https://leetcode.cn/problems/linked-list-cycle-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return nullptr;
        }
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while (fast->next && fast->next->next) {
            if (fast == slow) {
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};