//https://leetcode.cn/problems/delete-the-middle-node-of-a-linked-list/
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) {
            return nullptr;
        }
        ListNode* fast = head->next, * slow = head->next, * pre = head;
        while (fast->next && fast->next->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = slow->next;
        delete slow;
        return head;
    }
};