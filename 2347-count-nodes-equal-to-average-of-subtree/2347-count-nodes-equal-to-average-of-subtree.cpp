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
class Solution {
    pair<int, int> dfs(TreeNode* root, int& cnt)
    {
        if(root == NULL)
            return  {0, 0};
        pair<int, int>left = dfs(root->left, cnt);
        pair<int, int>right = dfs(root->right, cnt);
        int curr_sum = root->val + left.first + right.first;
        int curr_cnt =  1 +left.second + right.second;
        if(root->val == (curr_sum/curr_cnt))
            ++cnt; 
        return  {curr_sum, curr_cnt};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};