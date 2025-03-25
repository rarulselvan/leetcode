class Solution 
{
public:
    bool isPalindrome(int x) 
    {
        int temp = x;
        long reverse=0;
        
        if(temp<0)
            return false;
        
        while(temp)
        {
            int tail=temp%10;
            reverse=reverse*10+tail;
            temp=temp/10;
        }
        return (x==reverse);
    }
};