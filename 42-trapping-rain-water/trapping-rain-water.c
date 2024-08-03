int max(int a, int b)
{
    return a>b? a:b;
}
int min(int a, int b)
{
    return a>b? b:a;
}
int trap(int* arr, int n)
{
    int *leftSeen= (int *) malloc(sizeof(int)*(n+1)); 
	int *rightSeen=(int *) malloc(sizeof(int)*(n+1));
    int water=0;

    leftSeen[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        leftSeen[i]=max(leftSeen[i-1], arr[i]);
    }
    rightSeen[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        rightSeen[i]=max(rightSeen[i+1], arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        //printf("%d...%d\n",leftSeen[i], rightSeen[i]);
        water+= min(leftSeen[i],rightSeen[i])-arr[i]   ;   
    }
    return water;
}