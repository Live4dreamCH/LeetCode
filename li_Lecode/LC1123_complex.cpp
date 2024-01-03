/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        BFS(root);

        std::set<TreeNode *> node_set{max_depth_val_vec.begin(), max_depth_val_vec.end()};
        while (node_set.size() > 1)
        {
            std::set<TreeNode *> parent_set{};
            for (const auto node : node_set)
            {
                parent_set.emplace(parent_map[node]);
            }
            node_set.swap(parent_set);
        }
        if (node_set.empty())
        {
            return root;
        }
        return *(node_set.begin());
    }

private:
    void BFS(TreeNode *root)
    {
        if (nullptr == root)
        {
            return;
        }
        std::queue<std::pair<TreeNode *, int>> broad_queue{};
        broad_queue.emplace(root, 0);
        while (!broad_queue.empty())
        {
            TreeNode *curr = broad_queue.front().first;
            int depth = broad_queue.front().second;
            func(curr, depth);
            if (nullptr != curr->left)
            {
                broad_queue.emplace(curr->left, depth + 1);
            }
            if (nullptr != curr->right)
            {
                broad_queue.emplace(curr->right, depth + 1);
            }
            broad_queue.pop();
        }
    }

    void func(TreeNode *node, int depth)
    {
        if (nullptr == node)
        {
            return;
        }
        if (depth != max_depth)
        {
            max_depth = depth;
            max_depth_val_vec.clear();
        }
        max_depth_val_vec.emplace_back(node);

        if (nullptr != node->left)
        {
            parent_map.emplace(node->left, node);
        }
        if (nullptr != node->right)
        {
            parent_map.emplace(node->right, node);
        }
    }

    int max_depth = -1;
    std::vector<TreeNode *> max_depth_val_vec{};
    std::unordered_map<TreeNode *, TreeNode *> parent_map{};
};