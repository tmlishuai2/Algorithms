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
        
        reverse = 0
        while reverse < x:
            reverse = reverse * 10 + x % 10
            x = x // 10
        
        return reverse == x or reverse // 10 == x