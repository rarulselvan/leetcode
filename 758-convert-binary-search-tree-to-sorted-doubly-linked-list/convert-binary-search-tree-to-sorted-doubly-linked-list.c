/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
*/
static struct Node *prev=NULL;

void treeToDLL(struct Node *root, struct Node **head)
{
    if(root==NULL)
        return ;
    
    treeToDLL(root->left, head);
    if(prev==NULL)
    {
        *head=root;
        (*head)->left=NULL;
         printf("%d ...",(*head)->val);
    }
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    printf("%d ...",root->val);

    treeToDLL(root->right, head);
}


struct Node* treeToDoublyList(struct Node *root)
{
    prev=NULL;
    struct Node *result=NULL;
    treeToDLL(root, &result);
    return result;
}
