class Solution {
public:
    unordered_map<int, int> f;
    //vector<int>f;

    int minDays(int n) {
     //   f.resize(n+1, -1);
        return dfs(n);
    }

    int dfs(int n) {
        if (n < 2) {
            return n;
        }
        if (f[n]) 
            return f[n];
        
        int res = 1 + min(n % 2 + dfs(n / 2), n % 3 + dfs(n / 3));
        f[n] = res;
        return res;
    }
};