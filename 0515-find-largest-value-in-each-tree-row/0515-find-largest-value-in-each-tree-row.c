/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int depth(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    return l>r ? l+1 : r+1;
}

void dfs(struct TreeNode* root, int* arr, int level)
{
    if(root!= NULL)
    {
        arr[level] = fmax(arr[level], root->val);
       dfs(root->left, arr, level+1);
       dfs(root->right, arr, level+1);
    }
}
int* largestValues(struct TreeNode* root, int* returnSize){
    
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int size = depth(root);

    int* arr = (int*)malloc(size* sizeof(int));
    for(int i = 0; i<size; ++i)
        arr[i] = INT_MIN;
    dfs(root, arr, 0);
    *returnSize = size;
    return arr;
}