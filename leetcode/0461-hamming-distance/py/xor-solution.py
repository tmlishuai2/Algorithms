class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        result = 0
        num = x^y
        while num > 0:
            result += (num % 2)
            num = num // 2
            
        return result