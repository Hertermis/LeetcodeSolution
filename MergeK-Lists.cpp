//https://leetcode.cn/problems/vvXgSW/submissions/543604565/
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
#include <queue>
public:
	class comp {
	public:
		bool operator()(ListNode* Node1, ListNode* Node2) {
			return Node1->val > Node2->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, comp> pq;
		for (auto it = lists.begin(); it != lists.end(); it++) {
			if (*it != nullptr) {
				pq.emplace(*it);
			}
		}
		if (pq.empty()) return nullptr;
		ListNode* head = pq.top();
		ListNode* pre = head;
		pq.pop();
		if (head->next != nullptr) {
			pq.emplace(head->next);
		}
		while (!pq.empty()) {
			ListNode* cur = pq.top();
			pq.pop();
			pre->next = cur;
			pre = cur;
			if (cur->next != nullptr) {
				pq.emplace(cur->next);
			}
		}
		return head;
	}
};