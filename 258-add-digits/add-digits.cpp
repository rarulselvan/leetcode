class Solution {
public:
    // Function to add the digits of a number until the result is a single digit.
    int addDigits(int num)
     {
    int sum = 0;

    // Repetitively calculate sum until
    // it becomes single digit
    while (num > 0 || sum > 9) {

        // If n becomes 0, reset it to sum 
        // and start a new iteration.
        if (num == 0) {
            num = sum;
            sum = 0;
        }

        sum += num % 10;
        num /= 10;
    }
    return sum;
    }
};