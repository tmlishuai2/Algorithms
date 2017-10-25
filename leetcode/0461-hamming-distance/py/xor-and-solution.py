class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        result = 0
        diff = x^y
        while diff > 0:
            diff &= (diff - 1)
            result += 1
            
        return result