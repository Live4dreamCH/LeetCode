#include <vector>
#include <queue>
using std::vector;
using std::queue;

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > result;
        if (root == nullptr) {
            return result;
        }
        result.push_back(vector<int>{root->val});
        queue<TreeNode*> ptr;
        ptr.push(root);
        int layer = 0;  //父层层号
        bool exist; //子层是否有元素
        do {
            exist = false;
            for (int i = 0; i < result[layer].size(); ++i) {    //i: 父层元素下标
                if (ptr.front()->left != nullptr) {
                    if (exist) {
                        result[layer + 1].push_back(ptr.front()->left->val);
                    }
                    else {
                        result.push_back(vector<int>{ptr.front()->left->val});
                        exist = true;
                    }
                    ptr.push(ptr.front()->left);
                }
                if (ptr.front()->right != nullptr) {
                    if (exist) {
                        result[layer + 1].push_back(ptr.front()->right->val);
                    }
                    else {
                        result.push_back(vector<int>{ptr.front()->right->val});
                        exist = true;
                    }
                    ptr.push(ptr.front()->right);
                }
                ptr.pop();
            }
            ++layer;
        } while (exist);
        return result;
    }
};