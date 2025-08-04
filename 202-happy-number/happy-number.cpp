class Solution 
{
public:
    bool isHappy(int n) 
    {
        // Lambda function to calculate the next number by summing the squares of the digits
        auto getNextNumber = [](int currentNumber) 
        {
            int sumOfSquares = 0;
            while (currentNumber > 0) 
            {
                int digit = currentNumber % 10; // Get last digit
                sumOfSquares    = sumOfSquares + pow(digit, 2); // Add square of the digit to sum
                currentNumber   = currentNumber/10; // Remove the last digit
            }
            return sumOfSquares;
        };
      
        // Initialize two pointers for the cycle detection (Floyd's ALgorithm)
        int slowPointer = n; // Slow pointer moves one step
        int fastPointer = n;//getNextNumber(n); // Fast pointer moves two steps

        while(true)
        {
            slowPointer=getNextNumber(slowPointer);
            fastPointer=getNextNumber(getNextNumber(fastPointer));
            if(fastPointer==1)
                return true;
            else if(slowPointer==fastPointer)
                return false;
        }
    }
};