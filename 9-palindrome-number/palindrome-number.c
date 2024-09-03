bool isPalindrome(int x)
{
    long reverse = 0;
    long temp = x;
    if(temp<0)
        return false;
    while (temp != 0)
    {
        reverse = (reverse * 10) + (temp % 10);
        temp = temp / 10;
    }
    // If reverse is equal to the original number, the number is palindrome
    return (reverse == x);
}