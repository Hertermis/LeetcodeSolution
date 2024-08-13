//https://leetcode.cn/problems/aMhZSa/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) {
			return true;
		}
		//���е�
		ListNode* slow = head, * fast = head;
		while (fast->next && fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast->next) {
			fast = fast->next;
		}
		//��ת�������
		ListNode* ls = head;
		ListNode* rs = reverseLinkedList(slow);
		bool ans = true;
		//�Ƚ�
		while (ls && rs) {
			if (ls->val != rs->val) {
				ans = false;
				break;
			}
			ls = ls->next;
			rs = rs->next;
		}
		//�ָ�����
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