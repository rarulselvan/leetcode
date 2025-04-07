mod = 10**9 + 7
mx = 10**5
fac = [1] * (mx + 1)
for i in range(2, mx + 1):
    fac[i] = fac[i - 1] * i % mod

class Solution:
    def numberOfSequence(self, n: int, sick: List[int]) -> int:
        # Calculate the number of children in each segment
        nums = [b - a - 1 for a, b in pairwise([-1] + sick + [n])]
        # Start with the factorial of the total count of uninfected children
        s = sum(nums)
        ans = fac[s]
        # Divide by the factorial of the count in each segment
        for x in nums:
            if x:
                ans = ans * pow(fac[x], mod - 2, mod) % mod
        # Multiply by 2^(count-1) for non-border segments
        for x in nums[1:-1]:
            if x > 1:
                ans = ans * pow(2, x - 1, mod) % mod
        # Return the final result
        return ans