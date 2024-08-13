//https://leetcode.cn/problems/rotate-list/description/
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) {
            return head;
        }
        int size = 1;
        ListNode* fast = head, * slow = head;
        while (k--) {
            if (fast->next) {
                fast = fast->next;
                size++;
            }
            else {
                fast = head;
                k = k % size;
            }
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }
};