int numTrees(int n) 
{
    if(n==0 || n==1)
        return 1;
    
    int total=0;
    int left=0;
    int right=0;
    
    for(int i=0; i<n; i++)
    {
        left=numTrees(i);
        right=numTrees(n-1-i);
        total=total+(left*right);
    }
    return total;
}