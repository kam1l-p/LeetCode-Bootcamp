class Solution(object):
    def peopleAwareOfSecret(self, n, delay, forget):
        """
        :type n: int
        :type delay: int
        :type forget: int
        :rtype: int
        """
        MOD = 10**9 + 7
        dp = [0] * (n + 1)
        dp[1] = 1  

        for day in range(2, n + 1):
            for prev_day in range(max(1, day - forget + 1), day - delay + 1):
                dp[day] = (dp[day] + dp[prev_day]) % MOD
        result = 0
        for i in range(n - forget + 1, n + 1):
            result = (result + dp[i]) % MOD
        return result