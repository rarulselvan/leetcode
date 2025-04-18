class TwoSum 
{
unordered_map <int, int> Map;
public:
    TwoSum() {
        
    }
    
    void add(int number) 
    {
        Map[number]++;    
    }
    
  bool find(int value) {
        for (auto& [x, v] : Map) {
            long y = (long) value - x;
            if (Map.contains(y) && (x != y || v > 1)) {
                return true;
            }
        }
        return false;
    }

};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */