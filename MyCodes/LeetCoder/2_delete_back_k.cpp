/*
 * @Autor: zcshen
 * @Date: 2020-12-15 14:59:44
 * @Description: 删除链表的倒数第n个节点, 并返回头节点
 */

//  Definition for singly-linked list.

#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode* next) : val(x), next(next) {
    }
};

class Solution {
  public:
    // 栈实现
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack< ListNode* > auxiliary_stack;
        size_t node_numbers = 0;

        ListNode* node = head;
        while (node != nullptr) {
            // 计数
            ++node_numbers;
            // 节点指针入栈
            auxiliary_stack.push(node);
            node = node->next;
        }

        if (node_numbers < n) {
            // 直接返回
            return head;
        }

        if (node_numbers == n) {
            // 返回头节点的下一个节点
            return head->next;
        }

        ListNode* node_n_pre = nullptr;
        ListNode* node_n = nullptr;
        ListNode* tmp_node = nullptr;
        size_t back_index = 0;
        while (node_numbers--) {
            tmp_node = auxiliary_stack.top();
            auxiliary_stack.pop();
            ++back_index;
            if (back_index == n) {
                node_n = tmp_node;
            }
            else if (back_index == (n + 1)) {
                node_n_pre = tmp_node;
                node_n_pre->next = node_n->next;
                node_n->next = nullptr;
                break;
            }
        }

        return head;
    }

    // 快慢指针
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (nullptr == head || 0 == n) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (n > 0 && nullptr != fast) {
            --n;
            fast = fast->next;
        }

        if (nullptr == fast) {
            if (0 == n) {
                // 头节点被删除
                return head->next;
            }
            else {
                // n 超过链表总长度, 不存在倒数第n个节点, 直接返回头节点
                return head;
            }
        }

        while (nullptr != fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};
