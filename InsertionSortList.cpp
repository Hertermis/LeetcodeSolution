//https://leetcode.cn/problems/insertion-sort-list/description/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* sortedAreaHead = head, * cur = head->next, * nex;
        sortedAreaHead->next = nullptr;
        while (cur) {
            nex = cur->next;
            //��������ͷ��С
            if (cur->val <= sortedAreaHead->val) {
                cur->next = sortedAreaHead;
                sortedAreaHead = cur;
                cur = nex;
                continue;
            }
            ListNode* scur = sortedAreaHead->next, * spre = sortedAreaHead;
            while (scur) {
                //���������м��ҵ���
                if (cur->val <= scur->val) {
                    cur->next = scur;
                    spre->next = cur;
                    break;
                }
                spre = scur;
                scur = scur->next;
            }
            //��������β�ͻ���
            if (scur == nullptr) {
                cur->next = spre->next;
                spre->next = cur;
            }
            cur = nex;
        }
        return sortedAreaHead;
    }
};