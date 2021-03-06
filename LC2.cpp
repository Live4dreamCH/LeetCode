#include <iostream>
#include <vector>
using namespace std;

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *res = new ListNode;
        auto curr1 = l1, curr2 = l2, curr = res;
        // int carry = 0;
        while (curr1 != nullptr || curr2 != nullptr) {
            if (curr->next == nullptr) {
                curr->next = new ListNode();
            }
            curr = curr->next;
            if (curr1 != nullptr) {
                curr->val += curr1->val;
                curr1 = curr1->next;
            }
            if (curr2 != nullptr) {
                curr->val += curr2->val;
                curr2 = curr2->next;
            }
            if (curr->val > 9) {
                curr->next = new ListNode(curr->val / 10);
                curr->val %= 10;
            }
        }
        curr = res;
        res = res->next;
        delete curr;
        return res;
    }
};

int main() {
    Solution s;

    vector<int> a = {9, 9, 9, 9, 9, 9, 9}, b = {9, 9, 9, 9};
    ListNode *l1 = nullptr, *l2 = nullptr;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
        l1 = new ListNode(*it, l1);
    }
    for (auto it = b.rbegin(); it != b.rend(); ++it) {
        l2 = new ListNode(*it, l2);
    }
    auto res = s.addTwoNumbers(l1, l2);
    return 0;
}