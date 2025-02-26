class Solution {
public:
    int minDays(int n) 
    {
        if (n < 2) {
            return n;
        }
        //if (f.count(n)) {
       //     return f[n];
      //  }
        int res = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
       // f[n] = res;
        return res;
    }
};