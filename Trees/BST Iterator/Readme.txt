/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *nptr;
TreeNode *curr,*small;
stack<TreeNode*> st;
int done;
BSTIterator::BSTIterator(TreeNode *root) {
    nptr=root;
    curr=root;
    done=0;
    small==NULL;
    while(done==0)
    { if(curr!=NULL)
       {
           st.push(curr);
           curr=curr->left;
       }
      else
      {
         if(!st.empty())
         {
            curr=st.top();
            st.pop();
            small=curr;
            curr=curr->right;
            done=1;
         }
        else
         {
             done=1;
         }
      }
        
    }
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
   if(small==NULL)
    return false;
   else
    return true;
}

/** @return the next smallest number */
int BSTIterator::next() {
   
   TreeNode *nptr=small;
   done=0;
   while(done==0)
   {
       if(curr!=NULL)
       {
           st.push(curr);
           curr=curr->left; 
       }
       else
       {
        if(!st.empty())
         {
            curr=st.top();
            st.pop();
            small=curr;
            curr=curr->right;
            done=1;
         }
        else
         { small=NULL;
           done=1;
         }
       }
   }
   return nptr->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
