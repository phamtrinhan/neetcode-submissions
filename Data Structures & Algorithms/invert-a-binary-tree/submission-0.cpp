class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            swap(node->left, node->right);

            if (node->left) st.push(node->left);
            if (node->right) st.push(node->right);
        }

        return root;
    }
};