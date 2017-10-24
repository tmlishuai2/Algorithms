# Accepted
class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        length = len(s)
        max_sub = length - 1 # max subscript
        result = []
        if length <= numRows:
            return s
        if numRows == 1:
            return s
        
        # constant
        FIXED_STEP = 2 * numRows - 2
        
        # first line
        i = 0 # line number
        result.append(s[i::FIXED_STEP])
            
        # middle lines:
        if numRows > 2:
            for i in range(1, numRows - 1):
                max_k = (max_sub + i - FIXED_STEP) // FIXED_STEP + 1
                for k in range(max_k):
                    result.append(s[i+k*(FIXED_STEP)])
                    result.append(s[(k+1)*FIXED_STEP-i])
                if i + max_k * FIXED_STEP <= max_sub:
                    result.append(s[i+max_k*FIXED_STEP])
        
        # last line:
        i = numRows - 1
        result.append(s[i::FIXED_STEP])
                
        return ''.join(result)