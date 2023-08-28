#include <vector>
using std::vector;

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
    vector<ListNode *> splitListToParts(ListNode *head, int k) {
        if (head == nullptr) {
            return vector<ListNode *>(k, nullptr);
        }
        int len = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            curr = curr->next;
            ++len;
        }

        int base = len / k, remain = len % k, i = 0;
        curr = head;
        ListNode *prev = curr;
        vector<ListNode *> res{head};
        while (curr != nullptr) {
            if (remain != 0) {
                if (i == base + 1) {
                    prev->next = nullptr;
                    res.push_back(curr);
                    i = 0;
                    --remain;
                }
            } else {
                if (i == base) {
                    prev->next = nullptr;
                    res.push_back(curr);
                    i = 0;
                }
            }
            prev = curr;
            curr = curr->next;
            ++i;
        }
        res.resize(k, nullptr);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> vals{1, 2, 3};
    ListNode *head = nullptr;
    for (auto it = vals.rbegin(); it != vals.rend(); ++it) {
        head = new ListNode(*it, head);
    }
    int k = 5;
    s.splitListToParts(head, k);
    return 0;
}