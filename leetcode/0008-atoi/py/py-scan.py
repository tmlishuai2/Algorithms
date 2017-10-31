class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        length = len(str)
        if length == 0:
            return 0
        i = 0
        s = str[i]
        sign = 1
        nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        res = 0
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        
        while s == ' ':
            i += 1
            s = str[i]
            
        if s == '-':
            sign = -1
            i += 1
        elif s == '+':
            i += 1
            

        while i < length:
            if sign == 1 and res > INT_MAX:
                return INT_MAX
            if sign == -1 and res > -INT_MIN:
                return INT_MIN
            s = str[i]
            if s in nums:
                res = res * 10 + int(s)
                i += 1
                continue
            else:
                break
            
        return min(res, INT_MAX) if sign == 1 else max(-res, INT_MIN)