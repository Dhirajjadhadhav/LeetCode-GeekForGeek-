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
void inorder(TreeNode* root, int& max_freq, int& freq, int& val, vector<int>& ans)
{
    if(root == NULL)
        return ;
    inorder(root->left, max_freq, freq, val, ans);
    if(val==root->val)
        ++freq;
    else
    {
        val = root->val;
        freq = 1;
    }
    if(freq>max_freq){
        max_freq= freq;
        ans = {root->val};
    }
    else if(freq == max_freq)
        ans.push_back(root->val);
    inorder(root->right, max_freq, freq, val, ans);
    
}
public:
    vector<int> findMode(TreeNode* root) {
        int freq = 0;
        int max_freq = 0;
        int val = INT_MIN;
        vector<int>ans;

        inorder(root, max_freq, freq, val, ans);
        return ans;
    }
};