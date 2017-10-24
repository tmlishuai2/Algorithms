class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        
        if x < 0:
            return False
        if x % 10 == 0 and x != 0:
            return False
        if x < 10:
            return True
        if x < 100:
            return x % 11 == 0
        if x < 1000:
            return x // 100 == x % 10
        
        reverse = 0
        while reverse < x:
            reverse = reverse * 10 + x % 10
            x /= 10
        
        return reverse == x or reverse // 10 == x