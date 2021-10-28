struct ListNode {
    int val;
    ListNode *next;
    // 构造函数
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    // 拷贝构造函数
    // ListNode(const ListNode &another) {
    //     val = -another.val;
    //     next = another.next;
    // }
    // 赋值运算符重载
    // ListNode &operator=(const ListNode &ano) {
    //     val = ano.val + 1;
    //     int a = 0;
    //     return *this;
    // }
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

        if (left == right) {
            return head;
        } else if (left == 1) {
            rr = head;
            prev = head;
            scan = head->next;
            for (int i = 2; i < right + 1; i++) {

                if (i == right) {
                    if (scan->next != nullptr) {
                        rr->next = scan->next;
                        scan->next = prev;
                        head = scan;
                    } else {
                        rr->next = nullptr;
                        scan->next = prev;
                        head = scan;
                    }
                    break;
                } else if (i > left && i < right) {
                    curr = scan->next;
                    scan->next = prev;
                    prev = scan;
                    scan = curr;
                } else {
                    scan = scan->next;
                }
            }
            return head;
        } else {
            for (int i = 1; i < right + 1; i++) {

                if (i == left - 1) {
                    prev = scan;
                    scan = scan->next;
                    r = prev;
                } else if (i == left) {
                    prev = scan;
                    scan = scan->next;
                    rr = prev;
                } else if (i == right) {
                    if (scan->next != nullptr) {
                        r->next = scan;
                        rr->next = scan->next;
                        scan->next = prev;
                    } else {
                        r->next = scan;
                        scan->next = prev;
                        rr->next = nullptr;
                    }
                    break;
                } else if (i > left && i < right) {
                    curr = scan->next;
                    scan->next = prev;
                    prev = scan;
                    scan = curr;
                } else {
                    scan = scan->next;
                }
            }
            return head;
        }
    }
};

int main() {
    Solution s;
    // int values[] = {1, 2, 3, 4, 5};
    ListNode *a5 = new ListNode(3, nullptr);
    ListNode *a4 = new ListNode(5, a5);
    // ListNode *a3 = new ListNode(3, a4);
    // ListNode *a2 = new ListNode(2, a3);
    // ListNode *a1 = new ListNode(1, a2);

    // ListNode *head = nullptr;

    // for (int i = 4; i >= 0; --i) {
    //     head = new ListNode(values[i], head);
    // }
    s.reverseBetween(a4, 1, 2);
    return 0;
}