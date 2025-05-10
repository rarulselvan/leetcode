class RandomizedSet 
{
private:
    unordered_map<int, int>Map;
    vector<int> nums;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) 
    {
        if(Map.count(val))
        //if(Map[val])
            return false;
        
        nums.push_back(val);
        Map[val] = nums.size() - 1; // Store the index of val in nums
        return true;
    }
    
    bool remove(int val) 
    {
        if(!Map.count(val))
            return false;

        int idx = Map[val];           // Index of val to remove
        int lastVal = nums.back();    // Value at the end of nums

        // Move the last element to the place idx of the element to delete
        nums[idx] = lastVal;
        Map[lastVal] = idx;

        // Remove last element
        nums.pop_back();
        Map.erase(val);
        return true;
    }
    
    int getRandom() 
    {
        int randomIndex = rand() % nums.size();
        return nums[randomIndex];
    
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */