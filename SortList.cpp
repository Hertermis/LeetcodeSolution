//https://leetcode.cn/problems/sort-list/submissions/551976329/
//链表的归并排序-自顶向下（递归）
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
    ListNode* sortList(ListNode* head) {
        return mergeSort(head, nullptr);
    }
    ListNode* mergeSort(ListNode* head, ListNode* tail) {
        //边界
        if (head == nullptr) {
            return head;
        }
        //全断开连接
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        // 上中点
        ListNode* slow = head, * fast = head->next;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        return merge(mergeSort(head, slow), mergeSort(slow, tail));
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur1 = list1, * cur2 = list2, * tmp = dummyHead;
        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                tmp->next = cur2;
                tmp = cur2;
                cur2 = cur2->next;
            }
            else {
                tmp->next = cur1;
                tmp = cur1;
                cur1 = cur1->next;
            }
        }
        if (cur1) {
            tmp->next = cur1;
        }
        if (cur2) {
            tmp->next = cur2;
        }
        return  dummyHead->next;
    }
};
//链表的归并排序-自底向上（迭代）
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        //计算链表长度
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;
            node = node->next;
        }
        //哑巴节点
        ListNode* dummyHead = new ListNode(0, head);
        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, * curr = dummyHead->next;
            while (curr != nullptr) {
                //找到当前组别需要合并的第一个子链表的头
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                //找到当前组别需要合并的第二个子链表的头
                ListNode* head2 = curr->next;
                //将第一个子链表的尾部与第二个子链表的头部断开
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                //找到下一组并断开
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                //合并
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                //下一组
                curr = next;
            }
        }
        return dummyHead->next;
    }
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* cur1 = list1, * cur2 = list2, * tmp = dummyHead;
        while (cur1 && cur2) {
            if (cur1->val > cur2->val) {
                tmp->next = cur2;
                tmp = cur2;
                cur2 = cur2->next;
            }
            else {
                tmp->next = cur1;
                tmp = cur1;
                cur1 = cur1->next;
            }
        }
        if (cur1) {
            tmp->next = cur1;
        }
        if (cur2) {
            tmp->next = cur2;
        }
        return  dummyHead->next;
    }
};
//链表的快速排序（递归）