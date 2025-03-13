class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        index, n = 0, len(s)
        while index < n and s[index] == ' ':
            index += 1
        
        if index == n:
            return 0

        sign = 1
        if s[index] == '-':
            sign = -1
            index += 1
        elif s[index] == '+':
            index += 1

        result = 0
        while index < n and s[index].isdigit():
            result = result * 10 + int(s[index])
            index += 1

        result *= sign

        INT_MIN, INT_MAX = -2**31, 2**31 - 1
        if result < INT_MIN:
            return INT_MIN
        if result > INT_MAX:
            return INT_MAX

        return result