class Solution {
public:
    int divide(int dividend, int divisor) {


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

