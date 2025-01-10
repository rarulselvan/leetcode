class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        // Constructor remains empty as there's no initialization needed beyond that of member variables.
    }

    /**
    * Stores the key with its value along with the timestamp in the map.
    * The values associated with each key are stored in a vector of pairs, sorted by their timestamps.
    * @param key The string key of the value.
    * @param value The value to associate with the key.
    * @param timestamp The time at which the value was set.
    */
    void set(string key, string value, int timestamp) {
        // Appending the pair <timestamp, value> to the vector associated with the key.
        keyTimeValueMap[key].emplace_back(timestamp, value);
    }

    /**
    * Retrieves a value associated with the key at a particular timestamp.
    * If the specific timestamp doesn't exist, the value at the most recent timestamp before that is returned.
    * @param key The key whose value needs to be retrieved.
    * @param timestamp The timestamp at which the value was needed.
    * @return The value at the given timestamp or the last known value before the given timestamp.
    */
    string get(string key, int timestamp) {
        // Reference to the vector of pairs for the given key.
        auto& pairs = keyTimeValueMap[key];
      
        // Constructing a dummy pair up to the current timestamp to use in searching.
        pair<int, string> dummyPair = {timestamp, string({127})};  // 127 is used as the end of the range character.

        // Finding the upper bound, which will point at the first element that is greater than the dummy pair.
        auto it = upper_bound(pairs.begin(), pairs.end(), dummyPair);

        // If the iterator is at the beginning, there are no elements less than or equal to the timestamp,
        // hence return an empty string. Otherwise, decrement iterator to get to the element which has
        // the latest time less than or equal to the given timestamp.
        return it == pairs.begin() ? "" : (prev(it))->second;
    }

private:
    // Map that associates each key with a vector of pairs, where each pair consists of a timestamp 
    // and the value associated with that timestamp.
    unordered_map<string, vector<pair<int, string>>> keyTimeValueMap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */