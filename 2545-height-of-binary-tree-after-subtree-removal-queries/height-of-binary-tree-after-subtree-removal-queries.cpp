class Solution {
public:
    int max_height_after_removal[100001];
    int current_max_height = 0;

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        traverse_left_to_right(root, 0);
        current_max_height = 0;
        traverse_right_to_left(root, 0);

        vector<int> query_results(queries.size());
        for (int i = 0; i < queries.size(); i++) 
            query_results[i] = max_height_after_removal[queries[i]];

        return query_results;
    }

private:
    void traverse_left_to_right(TreeNode* node, int height) {
        if (node == nullptr) return;

        max_height_after_removal[node->val] = current_max_height;
        current_max_height = max(current_max_height, height);

        traverse_left_to_right(node->left, height + 1);
        traverse_left_to_right(node->right, height + 1);
    }

    void traverse_right_to_left(TreeNode* node, int height) {
        if (node == nullptr) return;

        max_height_after_removal[node->val] = max(max_height_after_removal[node->val], current_max_height);
        current_max_height = max(current_max_height, height);

        traverse_right_to_left(node->right, height + 1);
        traverse_right_to_left(node->left, height + 1);
    }
};