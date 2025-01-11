class Solution {
public:
    int prefixCount(vector<string>& words, string pref)
    {
        int ans = 0;
        for (string w : words) 
        {
            if(w.find(pref) == 0)//found the substring at oth index
                ans=ans+1;
        }
        return ans;
    }
};