/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    vector<vector<int>> ans;
    //int x=solve(ans,A);
    if(A!=NULL)
    {
        int p=0;
        TreeNode *nptr=A;
        map<int,vector<int>> m;
        queue<pair<TreeNode*,int>> qu;
        qu.push(make_pair(nptr,0));
        while(!qu.empty())
        {
            pair<TreeNode*,int> temp=qu.front();
            qu.pop();
            nptr=temp.first;
            p=temp.second;
            m[p].push_back(nptr->val);
            if(nptr->left!=NULL)
            {
                qu.push(make_pair(nptr->left,p-1));
            }
           if(nptr->right!=NULL)
           {
               qu.push(make_pair(nptr->right,p+1));
           }
            
        }
       auto itr=m.begin();
       while(itr!=m.end())
       {
           ans.push_back(itr->second);
           itr++;
       }
    }
   return ans;
}
