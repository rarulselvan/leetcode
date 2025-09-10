/*class Solution 
{
public:
    long long divide(long long dividend, long long divisor) 
    {
        if (divisor == 0) throw overflow_error("Divide by zero");
        if (dividend == LLONG_MIN && divisor == -1) return LLONG_MAX;

        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;

        unsigned long long a = llabs(dividend);
        unsigned long long b = llabs(divisor);

        long long quotient = 0;
        while (a >= b) 
        {
            a -= b;
            quotient++;
        }
        return sign * quotient;
    }
};
*/



class Solution {
public:
    int divide(int dividend, int divisor) {
        // optional: handle divide-by-zero as you prefer
        if (divisor == 0) throw std::overflow_error("Divide by zero");

        // overflow case: INT_MIN / -1 -> 2147483648 (doesn't fit in int)
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool negative = ((dividend < 0) ^ (divisor < 0));

        // work in unsigned long long for safe absolute-value arithmetic
        unsigned long long a = static_cast<unsigned long long>(std::llabs((long long)dividend));
        unsigned long long b = static_cast<unsigned long long>(std::llabs((long long)divisor));

        unsigned long long result = 0;
        while (a >= b) {
            unsigned long long temp = b, multiple = 1;
            // double temp until it would exceed a
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }
            a -= temp;
            result += multiple;
        }

        long long signedResult = negative ? -static_cast<long long>(result)
                                          : static_cast<long long>(result);

        // final safety check (shouldn't be needed because we handled the only overflow case)
        if (signedResult > INT_MAX) return INT_MAX;
        if (signedResult < INT_MIN) return INT_MAX; // consistent with LeetCode overflow handling

        return static_cast<int>(signedResult);
    }
};

