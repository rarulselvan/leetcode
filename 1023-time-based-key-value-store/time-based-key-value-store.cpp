
class TimeMap 
{
private:
    unordered_map<string, vector<pair<string, int>>> keyValStore;
public:
    TimeMap()
    {
        
    }
    void set(string key, string value, int timestamp) 
    {
        keyValStore[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp)
    {
        if (keyValStore.find(key) == keyValStore.end()) 
        {
            //not found
            return "";
        }
        
        int low = 0;
        int high = keyValStore[key].size() - 1;
        
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (keyValStore[key][mid].second < timestamp) 
            {
                low = mid + 1;
            } 
            else if (keyValStore[key][mid].second > timestamp)
            {
                high = mid - 1;
            } 
            else
            {
                return keyValStore[key][mid].first;
            }
        }
        
        if (high >= 0)
        {
            return keyValStore[key][high].first;
        }
        return "";
    }

};