/*
 * @Autor: zcshen
 * @Date: 2020-12-21 11:51:56
 * @Description: 合并两个有序链表
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if (nullptr == l1) {
    return l2;
  }
  else if (nullptr == l2) {
    return  l1;
  }

  ListNode* merged_header = nullptr;

  if (l1->val < l2->val) {
    merged_header = l1;
    merged_header->next = mergeTwoLists(l1->next, l2);
  }
  else {
    merged_header = l2;
    merged_header->next = mergeTwoLists(l1, l2->next);
  }

  return merged_header;
}

ListNode* createList(const std::vector<int>& vec) {
  if (vec.empty()) {
    return nullptr;
  }

  size_t len = vec.size();
  ListNode* node = nullptr;
  for (int i=len-1; i>=0; i--) {
    node = new ListNode(vec[i], node);
  }
 
  return node;
}


// 1 -> 2 -> 3
void print(ListNode* head) {
  if (nullptr == head)  {
    return;
  }

  cout << head->val;
  ListNode *node = head->next;
  while (nullptr != node)
  {
    cout << "->";
    cout << node->val;
    node = node->next;
  }

  cout << endl;
}


int main() {
  std::vector<int> vec {1,2,4,5};
  ListNode *list1 = createList(vec);
  print(list1);

  std::vector<int> vec2 {3,4,5,6,7};
  ListNode *list2 = createList(vec2);
  print(list2);

  ListNode *merge_header = mergeTwoLists(list1, list2);
  print(merge_header);

  return 0;
}
