class Solution {
public:
    int mySqrt(int n)
    {
    
    // Start iteration from 1 until the 
    // square of a number exceeds n
    long long res = 1;
    while(res*res <= n){
        res++;
    }
    
    // return the largest integer whose 
    // square is less than or equal to n
    return res - 1;
}
};