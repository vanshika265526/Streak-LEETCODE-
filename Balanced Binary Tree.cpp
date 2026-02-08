class Solution {
public:
    int checkHeight(TreeNode* root) {
        if (!root) return 0;

        int left = checkHeight(root->left);
        if (left == -1) return -1; // left subtree not balanced

        int right = checkHeight(root->right);
        if (right == -1) return -1; // right subtree not balanced

        if (abs(left - right) > 1) return -1; // current node not balanced

        return max(left, right) + 1; // return height
    }

    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};
