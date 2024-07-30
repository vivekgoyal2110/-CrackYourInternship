class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int depth = 0;

        rightSide(root, result, depth);

        return result;
    }

    void rightSide(TreeNode* root, vector<int>& result, int depth) {
        if (root == nullptr) {
            return;
        }

        if (result.size() == depth) {
            result.push_back(root->val);
        }

        depth++;

        rightSide(root->right, result, depth);
        rightSide(root->left, result, depth);
    }
};