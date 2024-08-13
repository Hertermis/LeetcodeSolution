//https://leetcode.cn/problems/remove-duplicates-from-an-unsorted-linked-list/description/
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
/*原解决方案*/
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> appeared;
        if (!head->next) {
            return head;
        }
        ListNode* cur = head;
        while (cur) {
            if (appeared.find(cur->val) == appeared.end()) {
                appeared.emplace(make_pair(cur->val, 1));
            }
            else {
                appeared[cur->val]++;
            }
            cur = cur->next;
        }
        //删除
        while (head && appeared[head->val] > 1) {
            head = head->next;
        }
        ListNode* pre = head, * nex;
        if (!head) {
            return nullptr;
        }
        cur = head->next;
        while (cur) {
            nex = cur->next;
            if (appeared[cur->val] > 1) {
                pre->next = nex;
            }
            else {
                pre = cur;
            }
            cur = nex;
        }
        return head;
    }
};
/*优化后的解决方案*/
class Solution {
public:
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> appeared;
        if (!head->next) {
            return head;
        }
        appeared.emplace(make_pair(head->val, 1));
        
        int maxCount = 1;
        ListNode* cur = head->next, * nex = nullptr, * pre = head;
        while (cur) {
            nex = cur->next;
            if (appeared.find(cur->val) == appeared.end()) {
                appeared.emplace(make_pair(cur->val, 1));
                pre = cur;
            }
            else {
                /*优化1：第一次遍历时就删去重复的部分，降低第二次遍历复杂度*/
                appeared[cur->val]++;
                pre->next = nex;
                maxCount = 0;
            }
            cur = nex;
        }
        /*优化2：第一次遍历后若数组无重复直接返回*/
        if (maxCount == 1) {
            return head;
        }
        while (head && appeared[head->val] > 1) {
            head = head->next;
        }
        pre = head; nex = nullptr;
        if (!head) {
            return nullptr;
        }
        cur = head->next;
        while (cur) {
            nex = cur->next;
            if (appeared[cur->val] > 1) {
                pre->next = nex;
            }
            else {
                pre = cur;
            }
            cur = nex;
        }
        return head;
    }
};