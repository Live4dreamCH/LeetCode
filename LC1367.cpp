#include "MyLib.h"
#include "KMP.h"
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        for (ListNode* curr = head;nullptr != curr; curr = curr->next) {
            sub.emplace_back(curr->val);
        }
        next = gen_KMP_next(sub);
        return this->isSubPathRecursive(0, root);
    }
private:
    bool isSubPathRecursive(int i,const TreeNode* root) {
        if (i >= sub.size()) {
            return true;
        }
        else if (nullptr == root) {
            return false;
        }

        while (sub[i] != root->val) {
            if (i == 0) {
                return this->isSubPathRecursive(0, root->left) || this->isSubPathRecursive(0, root->right);
            }
            i = next[i - 1];
        }
        return this->isSubPathRecursive(i + 1, root->left) || this->isSubPathRecursive(i + 1, root->right);
    }
    vector<int> sub;
    vector<int> next;
};

//class Solution {
//public:
//    bool isSubPath(ListNode* head, TreeNode* root) {
//        return this->isSubPathRecursive(head, root) || (root->left && this->isSubPath(head, root->left)) || (root->right && this->isSubPath(head, root->right));
//    }
//private:
//    bool isSubPathRecursive(ListNode* head, TreeNode* root) {
//        if (nullptr == head) {
//            return true;
//        }
//        else if (nullptr == root) {
//            return false;
//        }
//
//        if (head->val == root->val) {
//            return this->isSubPathRecursive(head->next, root->left) || this->isSubPathRecursive(head->next, root->right);
//        }
//        return false;
//    }
//};

//int main() {
//    Solution s;
//    // vector<string> v{ "ABC","ACB","ABC","ACB","ACB" };
//    // head = [4, 2, 8], root = [1, 4, 4, null, 2, 2, null, 1, null, 6, 8, null, null, null, null, 1, 3]
//    ListNode head2(8);
//    ListNode head1(2, &head2);
//    ListNode head(4, &head1);
//    TreeNode root3(3);
//    TreeNode root1(1);
//    TreeNode root8(8, &root1, &root3);
//    TreeNode root6(6);
//    TreeNode root2(2, &root6, &root8);
//    TreeNode root4(4, &root2, nullptr);
//    TreeNode root1l(1);
//    TreeNode root2l(2, &root1l, nullptr);
//    TreeNode root4l(4, nullptr, &root2l);
//    TreeNode root(1, &root4l, &root4);
//    s.isSubPath(&head, &root);
//    return 0;
//}