class Solution {
public:
    int removeDuplicates(vector<int>& arr)
    {
        // To track seen elements
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
        //remove the elements in arr 
        arr.erase(arr.begin()+s.size(), arr.end());
        //cout << s.size()<<"   "<<arr.size()<<endl;
        // Return the size of the array 
        // with unique elements
        return s.size(); 
        
    }
};
