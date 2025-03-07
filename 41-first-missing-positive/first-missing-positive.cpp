/*class Solution {
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
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_map<int, int> Map;
        // Add all elements into hash map
        for(int x: nums)
            Map[x]=1;
        
        int i=1;
        for( i=1; i<= (nums.size()); i++)
        {
            if(Map[i]==0) return i;
        }
        return i;
    }
};