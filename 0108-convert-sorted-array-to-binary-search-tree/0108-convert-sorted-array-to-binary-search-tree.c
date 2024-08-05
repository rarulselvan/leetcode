/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayTobalancedBST(int* nums, int start, int end)
{
    if(start<=end)
    {
        int mid=start+(end-start)/2;
        struct TreeNode *root= (struct TreeNode *)malloc(sizeof(struct TreeNode));
        root->val=nums[mid];
        root->left=sortedArrayTobalancedBST(nums, start, mid-1);
        root->right=sortedArrayTobalancedBST(nums, mid+1, end);
        return root;
    }
    else
        return NULL;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) 
{
    return sortedArrayTobalancedBST(nums, 0, numsSize-1);
}