#include <memory>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int GCD(const int a, const int b) {
  if (0 == b) {
    return a;
  }
  return GCD(b, a % b);
}

class Solution {
public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *curr = head, *next = head->next;
    while (nullptr != next) {
      // std::make_shared<ListNode>(GCD(curr->val,next->val), next);
      curr->next = new ListNode(GCD(curr->val, next->val), next);
      curr = next;
      next = curr->next;
    }
    return head;
  }
};