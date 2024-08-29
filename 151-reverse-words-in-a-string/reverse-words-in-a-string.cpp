//using namespace string;
class Solution {
public:
string reverseWords(string str)
    {
        // Split the string into words
        istringstream ss(str);
        string word; 
        vector<string> arr;
        
        while (ss >> word) 
            arr.push_back(word);

        // Reverse array of words  
        reverse(arr.begin(), arr.end());  
      
    // Join the words in reverse order  
    string Str;// = "";  
    for (string &s : arr)
    { 
        if(Str.empty())
            Str += (s + ""); 
        else
        {
            Str += " "; 
            Str += (s); 
        }

    }
   // trim_right(Str);

    return Str;
    }
};