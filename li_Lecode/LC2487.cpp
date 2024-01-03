#include <deque>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNodes(ListNode *head) {
    if (nullptr == head) {
      return head;
    }
    std::deque<ListNode *> desc_deque; // 单调递减队列
    ListNode *curr = head;
    while (nullptr != curr) {
      while (!desc_deque.empty() && curr->val > desc_deque.back()->val) {
        desc_deque.pop_back();
      }
      desc_deque.emplace_back(curr);
      curr = curr->next;
    }
    ListNode *new_head = desc_deque.front();
    curr = new_head;
    for (int i = 1; i < desc_deque.size(); ++i) {
      curr->next = desc_deque.at(i);
      curr = desc_deque.at(i);
    }
    curr->next = nullptr;
    return new_head;
  }
};