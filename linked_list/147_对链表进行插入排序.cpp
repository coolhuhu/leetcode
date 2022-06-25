// 2022-06-20

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
        if (!head) {
            return head;
        }
        ListNode* fake = new ListNode(0, head);
        // p 指向已知有序片段的最后一个节点
        ListNode* p = head;
        // cur 指向待插入的节点
        ListNode* cur = head->next;
        while (cur) {
            if (p->val <= cur->val) {
                p = p->next;
            }
            else {
                ListNode* pre = fake;
                // 找到比cur节点值大的第一个节点的前一个节点
                while (pre->next->val <= cur->val) {
                    pre = pre->next;
                }
                // 将节点插入
                p->next = cur->next;
                cur->next = pre->next;
                pre->next = cur;
            }
            // 更新待插入的节点
            cur = p->next;
        }
        return fake->next;
    }
};