class Solution 
{
public:
    bool check(vector<int>& nums) 
    {
        int count = 0;
        int n=nums.size();
        // Iterate through the vector
        for (int i = 0; i < n; i++) 
        {
            int nextEle= i+1;
            if(nextEle ==n)
                nextEle=0;
            if (nums[i] > nums[nextEle]) 
                count++;
    }

    // Return true if there is at most one point where the
    // sequence is out of order

    if(count>1)        
        return false;
    else
        return true;

    }
};