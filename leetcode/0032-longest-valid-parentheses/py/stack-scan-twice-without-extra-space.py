def longestValidParentheses(s):
    """
    :type s: str
    :rtype: int
    """

    left = 0
    right = 0
    length = len(s)
    longest = 0

    # from left to right
    current_start = 0
    for i in range(length):
        if s[i] == '(':
            left = left + 1
        else:
            right = right + 1

        if left == right and i + 1 - current_start > longest:
            longest = i + 1 - current_start
        if right > left:
            right = left = 0
            current_start = i + 1

    # from right to left
    right = left = 0
    current_start = length - 1
    for j in range(length - 1, -1, -1):
        if s[j] == ')':
            right = right + 1
        else:
            left = left + 1

        if left == right and current_start - j + 1 > longest:
            longest = current_start - j + 1
        if left > right:
            left = right = 0
            current_start = j - 1

    return longest

s = "(()"
print(longestValidParentheses(s))
