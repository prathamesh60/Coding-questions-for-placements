/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define li 1003
void solve(TreeNode* A,int &sum1,int &sum2)
{
    if(A==NULL)
    {
        sum1=(sum1+sum2)%li;
    }
    else
    {
        int temp=sum2;
        int p=A->val;
        sum2=(((sum2*10)%li) + p)%li;
        if(A->left!=NULL && A->right!=NULL)
        {
            solve(A->left,sum1,sum2);
            solve(A->right,sum1,sum2);
        }
        else if(A->left!=NULL)
         {
             solve(A->left,sum1,sum2);
         }
        else
         {
             solve(A->right,sum1,sum2);
         }
        sum2=temp;
    }
}
int Solution::sumNumbers(TreeNode* A) {
    int sum1=0,sum2=0;
    solve(A,sum1,sum2);
    return sum1;
}
