class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        length = len(s)
        longest = 1
        longest_i, longest_j = 0, 1

        # center of substring is s[i]
        for center in range(length):
            i = center
            j = i + 1
            sub_length = 1
            head = s[i]
            tail = s[j-1]
            while i > 0 and j < length:
                i -= 1
                j += 1
                head = s[i]
                tail = s[j-1]
                if head == tail:
                    sub_length += 2
                else:
                    i += 1
                    j -= 1
                    break
            if sub_length > longest:
                longest = sub_length
                longest_i, longest_j = i, j

        # center of substring is between s[i] and s[i+1]
        for center in range(length - 1):
            i = center # left index
            j = i + 2 # right index (tail)
            sub_length = 0
            head = s[i]
            tail = s[j-1]
            if head == tail:
                sub_length = 2
                if sub_length > longest:
                    longest = sub_length
                    longest_i, longest_j = i, j
            else:
                continue
            while i > 0 and j < length:
                i -= 1
                j += 1
                head = s[i]
                tail = s[j-1]
                if head == tail:
                    sub_length += 2
                else:
                    i += 1
                    j -= 1
                    break
            if sub_length > longest:
                longest = sub_length
                longest_i, longest_j = i, j

        return s[longest_i:longest_j]
