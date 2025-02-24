class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        vector<int> candies(n, 1);  // Step 1: Give each child at least one cand

        for(int i=1; i<n; i++)
        {
            if(ratings[i]>ratings[i-1])
                candies[i]=candies[i-1]+1; //i-1 here
        }
         for(auto x: candies)
            cout << x<< " ";
            cout <<endl;
       for(int i=n-2; i>=0; i--)
        {
            if(ratings[i]>ratings[i+1])
                candies[i]=max(candies[i], candies[i + 1] + 1); //i+1 here
        }
        for(auto x: candies)
            cout << x<< " ";
        return accumulate(candies.begin(), candies.end(), 0);
    }
};