class Solution 
{
public:
    int numTrees(int n) 
    {
        vector<int>memo(n+1, -1);//initialize with -1
        return numTreesDP(n, memo);
    }
    
private:
    int numTreesDP(int n, vector<int>& memo) 
    {
        if (n <= 1)//For n==0 "one null tree". For n=1 "tree with one node". Hence both cases "1" will be returned
            return 1;
        
        if (memo[n] != -1)
            return memo[n];
        
        int count = 0;
        for (int i = 0; i < n; i++)
            count += numTreesDP(i, memo) * numTreesDP(n - i - 1, memo);
            //The total BSTs for n nodes is the sum of all possible left-right subtree combinations:
            //Total = Σ [left_subtrees(i) × right_subtrees(n - i - 1)] for all i from 0 to n-1.
        
        memo[n] = count;
        return count;
    }
};