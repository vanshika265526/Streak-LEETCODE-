/*
Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

Note that you need to maximize the answer before taking the mod and not after taking it.*/

class Solution {
public:
    long long totalSum = 0;
    long long maxProd = 0;
    const long long MOD = 1e9 + 7;

    // First pass: get total sum of tree
    long long getTotalSum(TreeNode* root) {
        if(!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second pass: compute subtree sums & update max product
    long long dfs(TreeNode* root) {
        if(!root) return 0;

        long long currSum = root->val + dfs(root->left) + dfs(root->right);

        long long product = currSum * (totalSum - currSum);
        maxProd = max(maxProd, product);

        return currSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};
