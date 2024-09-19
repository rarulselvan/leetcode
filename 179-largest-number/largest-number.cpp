class Solution
{
    public:
        bool myCompare(const int& X, const int& Y)
        {
            return (X + Y) > (Y + X);
        }
        string largestNumber( vector<int>& nums)
        {
            vector<string> vs;
            for(int v:nums)
                vs.push_back(to_string(v));

            sort(vs.begin(), vs.end(), [](string& a, string& b) 
                {
                return a + b > b + a;
                }
            );

            if (vs[0] == "0") return "0";
            string ans;
            for (string v : vs)
                ans += v;
            return ans;
        }
        
};
