class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        freq = {}
        for n in nums:
            freq[n] = freq.get(n, 0) + 1
        return sorted(freq, key=freq.get, reverse=True)[:k]