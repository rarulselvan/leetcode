class Solution:
    def twoSum(self, nums: List[int], target: int):

        left=0 
        right=len(nums)-1
        
        while left < right:
            sum = nums[left]+nums[right]
            if sum < target:
                left +=1
            elif sum > target:
                right -=1
            else:
                return [left+1, right+1]

        return []

        