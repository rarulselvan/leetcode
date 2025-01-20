class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        unordered_map<int, bool> myMap;
        // Add all elements into hash map
        for(int x: nums)
            myMap[x]=true;
        
        int i=1;
        for(i=1; i<= (nums.size()+1); i++)
            if(myMap[i]==false) return i;
    
        return ++i;
    }
};