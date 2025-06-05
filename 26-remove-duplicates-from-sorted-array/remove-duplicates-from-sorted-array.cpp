class Solution 
{
public:
    int removeDuplicates(vector<int>& arr)
    {
        unordered_set<int> s; 
    
        // To maintain the new size of the array
        int idx = 0;  

        for (int i = 0; i < arr.size(); i++)
        {
            if (s.find(arr[i]) == s.end()) 
            { 
                s.insert(arr[i]);  
                arr[idx] = arr[i];  
                idx++;
            }
        }
        //Truncate the array 
        arr.erase(arr.begin()+s.size(), arr.end());
        return s.size();         
    }
};
