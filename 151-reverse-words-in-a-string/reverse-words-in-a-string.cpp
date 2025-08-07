//using namespace string;
class Solution 
{
    public:
        string reverseWords(string sentence)
        {
            // Split the string into words
            stringstream ss(sentence);
            string word; 
            vector<string> arr;
          
            //get all the strings in the sentence "str"
            while (ss >> word) 
                arr.push_back(word);

            // Reverse array of words  
            reverse(arr.begin(), arr.end());  
        
            // Join the words in reverse order  
            string res;
            for (string s : arr)
            {
                if(res.empty())
                    res=res+s;
                else
                    res=res+" "+s;
            }
            return res;
        }
};