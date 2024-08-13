//https://leetcode.cn/problems/aMhZSa/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) {
			return true;
		}
		//找中点
		ListNode* slow = head, * fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast->next) {
			fast = fast->next;
		}
		//反转后半链表
		ListNode* ls = head;
		ListNode* rs = reverseLinkedList(slow);
		bool ans = true;
		//比较
		while (ls && rs) {
			if (ls->val != rs->val) {
				ans = false;
				break;
			}
			ls = ls->next;
			rs = rs->next;
		}
		//恢复链表
		reverseLinkedList(slow);
		return ans;
	}
	ListNode* reverseLinkedList(ListNode* head) {
		if (!head->next) {
			return head;
		}
		ListNode* cur = head, * nex = head, * pre = nullptr;
		while (cur) {
			nex = nex->next;
			cur->next = pre;
			pre = cur;
			cur = nex;
		}
		return pre;
	}
};