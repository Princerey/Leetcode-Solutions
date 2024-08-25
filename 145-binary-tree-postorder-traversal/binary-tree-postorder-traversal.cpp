class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> s;
        TreeNode* lastVisited = nullptr;
        TreeNode* current = root;

        while (!s.empty() || current) {
            if (current) {
                s.push(current);
                current = current->left;
            } else {
                TreeNode* node = s.top();
                if (node->right && lastVisited != node->right) {
                    current = node->right;
                } else {
                    res.push_back(node->val);
                    lastVisited = node;
                    s.pop();
                }
            }
        }

        return res;
    }
};