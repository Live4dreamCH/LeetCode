#include "pch.h"

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right)
            return head;
        ListNode* beforeLeftP = nullptr, * leftP = nullptr, * preP = nullptr, * currP = head, * nextP = nullptr, * rightP = nullptr, * afterRightP = nullptr;
        int count = 1;
        while (currP != nullptr) {
            if (count == left - 1)
                beforeLeftP = currP;
            else if (count == left) {
                leftP = currP;
                preP = currP;
            }
            else if (count > left && count <= right) {
                nextP = currP->next;
                currP->next = preP;
                preP = currP;

                if (count == right) {
                    rightP = currP;
                    afterRightP = nextP;

                    if (beforeLeftP != nullptr)
                        beforeLeftP->next = rightP;
                    else
                        head = rightP;
                    leftP->next = afterRightP;

                    break;
                }

                currP = nextP;
                ++count;
                continue;
            }
            currP = currP->next;
            ++count;
        }
        return head;
    }
};