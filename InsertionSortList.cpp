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
            //比排序区头还小
            if (cur->val <= sortedAreaHead->val) {
                cur->next = sortedAreaHead;
                sortedAreaHead = cur;
                cur = nex;
                continue;
            }
            ListNode* scur = sortedAreaHead->next, * spre = sortedAreaHead;
            while (scur) {
                //在排序区中间找到了
                if (cur->val <= scur->val) {
                    cur->next = scur;
                    spre->next = cur;
                    break;
                }
                spre = scur;
                scur = scur->next;
            }
            //比排序区尾巴还大
            if (scur == nullptr) {
                cur->next = spre->next;
                spre->next = cur;
            }
            cur = nex;
        }
        return sortedAreaHead;
    }
};