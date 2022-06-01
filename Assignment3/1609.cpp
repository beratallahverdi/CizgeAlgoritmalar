class Solution
{
public:
    bool isEvenOddTree(TreeNode *root)
    {
        if (!root)
            return 0;
        int level = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            int n = Q.size();
            int prev = level % 2 ? INT_MAX : INT_MIN;
            for (int i = 0; i < n; ++i)
            {
                TreeNode *node = Q.front();
                Q.pop();
                if (level % 2 == 0)
                {
                    if (node->val % 2 == 0 || node->val <= prev)
                        return false;
                }
                else
                {
                    if (node->val % 2 == 1 || node->val >= prev)
                        return false;
                }
                prev = node->val;
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            level++;
        }
        return true;
    }
};