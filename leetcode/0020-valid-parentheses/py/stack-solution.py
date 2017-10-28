class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = ['b']
        pair = {
            '(': ')',
            '[': ']',
            '{': '}',
            'b': ''
        }
        for c in s:
            if c in '([{':
                stack.append(c)
            elif c == pair[stack[-1]]:
                stack.pop()
            else:
                return False
        return len(stack) == 1