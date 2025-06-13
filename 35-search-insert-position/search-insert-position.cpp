class Solution 
{
public:
    int searchInsert(vector<int> arr, int k) 
    {
        int i=0;
        for(int x :arr)
        {
            // If k is found or needs to be inserted 
            // before arr[i]
            if(x >= k) 
                return i;  
            i++;
        }
        // If k is greater than all elements,
        // insert at the end
        return arr.size();
    }  
};