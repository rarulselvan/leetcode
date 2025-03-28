class Solution 
{
public:
    vector<int> findBuildings(vector<int>& heights) 
    {
        vector<int> ans;
        int max = 0;
        
        for(int i=heights.size()-1; i>=0; i--)
        {
            if(max<heights[i])
            {
                max=heights[i];
                ans.push_back(i);
            }            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};