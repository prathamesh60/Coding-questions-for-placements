int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>>m;
    for(int i=0;i<A.size();i++)
    {
        m.push_back(make_pair(A[i],i));
    }
    sort(m.begin(),m.end());
    int n=A.size();
    int maxrightind[n];
    maxrightind[n-1]=m[n-1].second;
    for(int i=n-2;i>=0;i--)
    {
        maxrightind[i]=max(maxrightind[i+1],m[i].second);
    }
    int maxdiff=0;
    for(int i=0;i<n;i++)
    {
        int currdiff=maxrightind[i]-m[i].second;
        if(currdiff>maxdiff)
            maxdiff=currdiff;
    }
    return maxdiff;
}
