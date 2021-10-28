#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        ListNode *r = new ListNode;
        ListNode *rr = new ListNode;
        ListNode *prev = new ListNode;
        ListNode *curr = new ListNode;
        ListNode *scan = new ListNode;
        scan = head;

        for (int i = 1; i < right + 1; i++) {
            if (i == left - 1) {
                prev = scan;
                scan = scan->next;
                prev->next = r;
            }
            if (i == left) {
                prev = scan;
                scan = scan->next;
                prev->next = rr;
            }
            if (i == right) {
                if (scan->next != nullptr) {
                    r = scan;
                    rr = scan->next;
                } else {
                    r = scan;
                    rr = nullptr;
                }
                break;
            }
            if (i > left && i < right) {
                curr = scan->next;
                scan->next = prev;
                scan = curr;
            } else {
                scan = scan->next;
            }
        }
        return head;
    }
};

int main() {
    ListNode *top = new ListNode;
    ListNode *m = new ListNode;
    top->val = 5;
    int left = 2, right = 4;
    for (int i = 4; i > 0; i--) {
        ListNode *head = new ListNode;
        head->val = i;
        head->next = top;
        top = head;
    }
    m = reverseBetween(*top, left, right);
}