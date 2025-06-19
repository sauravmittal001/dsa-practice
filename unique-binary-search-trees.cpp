/**
 * https://www.interviewbit.com/problems/unique-binary-search-trees/
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> buildTrees(int start, int end) {
    vector<TreeNode*> trees;
    if (start > end) {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; ++i) {
        vector<TreeNode*> leftSubTrees = buildTrees(start, i - 1);
        vector<TreeNode*> rightSubTrees = buildTrees(i + 1, end);

        for (TreeNode* left : leftSubTrees) {
            for (TreeNode* right : rightSubTrees) {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                trees.push_back(root);
            }
        }
    }
    return trees;
}

vector<TreeNode*> Solution::generateTrees(int A) {
    if (A == 0) { return {}; }
    return buildTrees(1, A);
}
