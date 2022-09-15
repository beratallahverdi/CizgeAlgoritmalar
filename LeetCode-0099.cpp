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
class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void recoverTree(TreeNode *root)
    {
        TreeNode *first = nullptr;
        TreeNode *second = nullptr;
        TreeNode *pre = nullptr;
        TreeNode *cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                if (pre != nullptr && pre->val > cur->val)
                {
                    if (first == nullptr)
                        first = pre;
                    second = cur;
                }
                pre = cur;
                cur = cur->right;
            }
            else
            {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;
                if (node->right == nullptr)
                {
                    node->right = cur;
                    cur = cur->left;
                }
                else
                {
                    if (pre != nullptr && pre->val > cur->val)
                    {
                        if (first == nullptr)
                            first = pre;
                        second = cur;
                    }
                    pre = cur;
                    node->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};