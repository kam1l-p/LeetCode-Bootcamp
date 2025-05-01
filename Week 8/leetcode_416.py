class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total = sum(nums)
        
        if total % 2 != 0:
            return False
        
        target = total // 2
        n = [False] * (target + 1)
        n[0] = True  

        for num in nums:
            for j in range(target, num - 1, -1):
                n[j] = n[j] or n[j - num]
        
        return n[target]
