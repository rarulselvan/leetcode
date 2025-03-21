class Solution 
{
public:
    int countPrimes(int n) 
    {
        vector<bool> isPrime(n, true); // Create a vector of boolean values, filled with 'true', representing prime status
        int primeCount = 0; // Initialize a count of prime numbers
      
        // Use the Sieve of Eratosthenes algorithm to find all primes less than n
        for (int i = 2; i < n; ++i) 
        { // Start at the first prime, 2, and check up to n
            if (isPrime[i]) 
            { // If the number is marked as prime
                ++primeCount; // Increment the count of primes
                // Mark all multiples of i as not prime starting from i^2 to avoid redundant work (i * i can be optimized to skip non-primes)
                for (long long j = (long long)i * i; j < n; j += i) 
                {
                    isPrime[j] = false; // Mark the multiple as not prime
                }
            }
        }
        return primeCount; // Return the total count of primes found
    }
};