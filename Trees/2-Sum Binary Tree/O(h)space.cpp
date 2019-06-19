/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int Solution::t2Sum(TreeNode* A, int B) {
    if(A==NULL)
     return 0;
    else
    {  
      
      stack<TreeNode*> s1;
      stack<TreeNode*> s2;
      TreeNode *curr1=A,*curr2=A;
      int done1=0,done2=0;
      int val1=0,val2=0;
      while(done1==0 || done2==0)
      {
          while(done1==0)
          {
              if(curr1!=NULL)
              {
                  s1.push(curr1);
                  curr1=curr1->left;
                  
              }
             else
             {  if(s1.empty())
                {
                   done1=1; 
                }
                else
                {
                 curr1=s1.top();
                 s1.pop();
                 val1=curr1->val;
                 curr1=curr1->right;
                 done1=1;
                }
             }
          }
         while(done2==0)
         {
             if(curr2!=NULL)
              {
                  s2.push(curr2);
                  curr2=curr2->right;
                  
              }
             
             else
             {  if(s2.empty())
                 {
                    done2=1; 
                 }
                else
                {
                 curr2=s2.top();
                 s2.pop();
                 val2=curr2->val;
                 curr2=curr2->left;
                 done2=1;
                }
             }
         }
         if(val1<val2 && val1+val2==B)
          return 1;
         else if(val1<val2 && val1+val2<B)
          done1=0;
         else if(val1<val2 && val1+val2>B)
          done2=0;
      }
      return 0;
    }
}
