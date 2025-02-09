/*class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> Map;
        for (int num : nums)
            Map[num]++;
        vector<pair<int, int>> arr;
        for(pair<int, int> x: Map)
            arr.push_back(x);//{x.second, x.first});
        
        sort(arr.rbegin(), arr.rend());

        vector <int> res;
        for(int i=0; i<k; i++)
            res.push_back(arr[i].second);
        
        for(auto x : res)
            cout <<x <<" "; 
        return res;
     
    }
};*/
class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> Map;
        for (int num : nums)
            Map[num]++;

        //priority_queue<T, Container, Comparator> is the general syntax.
        //pair<int, int> is used as T.
        //vector<pair<int, int>> is the container.
        //greater<pair<int, int>> ensures a min-heap, sorting pairs by the first element (default behavior for pair).

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        //priority_queue<<pair<int, int>> minHeap;
        // Iterate over the frequency map.
        for (const auto& element : Map) 
        {
            int number = element.first;
            int frequency = element.second;
            minHeap.push({frequency, number});// Push the frequency first and number second... for the heap comaprision

            // If the heap size exceeds k, remove the least frequent element.This ensures that the heap always contains the top k frequent elements.
            if (minHeap.size() > k)
                minHeap.pop();
        }
        vector<int> res;
        for(int i=0; i<k;i++)
        {
            auto x=minHeap.top();
            res.push_back(x.second);
            minHeap.pop();
        }
        return res;
    }
};