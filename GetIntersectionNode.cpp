//https://leetcode.cn/problems/3u1WK4/
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
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		if (!headA || !headB) {
			return nullptr;
		}
		int sizeA = 0, sizeB = 0;
		ListNode* curA = headA, * curB = headB;
		while (curA->next && curB->next) {
			++sizeA;
			++sizeB;
			curA = curA->next;
			curB = curB->next;
		}
		while (curA->next) {
			++sizeA;
			curA = curA->next;
		}
		while (curB->next) {
			++sizeB;
			curB = curB->next;
		}
		if (curA != curB) {
			return nullptr;
		}
		curA = sizeA > sizeB ? headA : headB;
		curB = sizeA <= sizeB ? headA : headB;
		for (int i = 0; i < abs(sizeA - sizeB); i++) {
			curA = curA->next;
		}
		while (curA != curB) {
			curA = curA->next;
			curB = curB->next;
		}
		return curA;
	}
};