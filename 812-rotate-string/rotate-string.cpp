class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        if (s.size() != goal.size()) 
            return false; 
            
      	s += s;
  
      	// find s2 in concatenated string
  	    if (s.find(goal) == string::npos)
            return false;
        else
            return true;
    }
};