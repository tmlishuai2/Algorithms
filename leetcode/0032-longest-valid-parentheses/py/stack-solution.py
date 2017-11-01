def longestValidParentheses(s):
    """
    :type s: str
    :rtype: int
    """

    stack = [-1]
    longest = 0
    current_length = 0
    for i in range(len(s)):
        if s[i] == '(':
            stack.append(i)
        else:
            if len(stack) > 1:
                stack.pop()
                current_length = i - stack[-1]
            elif not stack:
                stack.append(i)
            else:
                stack.pop()
                stack.append(i)
            if current_length > longest:
                longest = current_length

    return longest


s = ")()())()()("
print(longestValidParentheses(s))
