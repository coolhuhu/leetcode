// 2022-06-21

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (head == NULL) {
            Node* node = new Node(insertVal);
            node->next = node;
            return node;
        }
        if (head->next == head) {
            Node* node = new Node(insertVal, head);
            head->next = node;
            return head;
        }
        Node* cur = head;
        Node* next = head->next;
        while (next != head) {
            if (insertVal >= cur->val && insertVal <= next->val) {
                // 查找到插入的位置
                break;
            }
            if (cur->val > next->val) {
                // 遍历到循环列表的头尾结点
                if (insertVal >= cur->val || insertVal <= next->val) {
                    break;
                }
            }
            cur = cur->next;
            next = next->next;
        }
        Node* node = new Node(insertVal, next);
        cur->next = node;
        return head;
    }
};