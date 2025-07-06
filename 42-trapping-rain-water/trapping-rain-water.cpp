class Solution 
{
public:
    int trap(vector<int>& height)
    {
        vector<int>leftSeen(height.size());
        vector<int>rightSeen(height.size());
        int n=height.size();
       
        //Compute Left Maximum Heights  for every position
        leftSeen[0]=height[0];
        for(int i=1; i<n; i++)
        {
            leftSeen[i]=max (leftSeen[i-1], height[i]);
        }

        //Compute Left Maximum Heights for every position
        rightSeen[n-1]=height[n-1];
        for(int i=n-2; i>=0; i--)
        {
            rightSeen[i]=max(rightSeen[i+1], height[i]);
        }

        //get the minium of leftseen and rightseen ..from the subtract the particular position
        int water=0;
        for(int i=1; i<n; i++)
        {    
            water+= min(leftSeen[i],rightSeen[i])-height[i];   
        }
        return water;
    }
};
/*

int trap(int* arr, int n)
{
    int *leftSeen= (int *) malloc(sizeof(int)*(n+1)); 
	int *rightSeen=(int *) malloc(sizeof(int)*(n+1));
    int water=0;

    leftSeen[0]=arr[0];
    for(int i=1; i<n; i++)
    {
        //construct an array gives a value highest from the left
        leftSeen[i]=max(leftSeen[i-1], arr[i]);
    }
    rightSeen[n-1]=arr[n-1];
    for(int i=n-2; i>=0; i--)
    {
        //construct an array gives a value highest from the right
        rightSeen[i]=max(rightSeen[i+1], arr[i]);
    }

    for(int i=0; i<n; i++)
    {
        //get the minium of leftseen and rightseen ..from the subtract the particular position
        water+= min(leftSeen[i],rightSeen[i])-arr[i]   ;   
    }
    return water;
}*/

