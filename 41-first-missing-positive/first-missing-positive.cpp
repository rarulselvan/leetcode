class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_map<int, bool> Map;
        // Add all elements into hash map
        for(int x: nums)
            Map[x]=true;
        
        int i=1;
        for( i=1; i<= (nums.size()); i++)
        {
            if(Map[i]==false) return i;
        }
        return i;
    }
};