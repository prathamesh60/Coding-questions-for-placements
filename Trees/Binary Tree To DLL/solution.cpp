/*This is a function problem.You only need to complete the function given below*/
/* Structure for tree and linked list
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// This function should convert a given Binary tree to Doubly
// Linked List
void solve(Node* root,Node* &prev,Node **head_ref)
{
    if(root!=NULL)
    {
        solve(root->left,prev,head_ref);
        if(prev==NULL)
         {
            *head_ref=root;
            // root->left=NULL;
             prev=root;
             
              
         }
        else
         {
            root->left=prev;
            prev->right=root;
            prev=root;
         }
        solve(root->right,prev,head_ref);
    }
}
void bToDLL(Node *root, Node **head_ref)
{
    Node *prev=NULL;
    solve(root,prev,head_ref);
}
