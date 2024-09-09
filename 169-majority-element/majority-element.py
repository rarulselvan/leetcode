from collections import defaultdict

class Solution:
    def majorityElement(self, nums):
        mp = defaultdict(int)
        n = len(nums) // 2

        for a in nums:
            mp[a] += 1

        ans = 0

        for a in mp.items():
            if a[1] > n:
                ans = a[0]

        return ans