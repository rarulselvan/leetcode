class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> myMap;
        for(auto x: nums)
            myMap[x]++;
        
        for( auto x: myMap)
            if(x.second==1)
                return x.first;
        return -1;
    }
};