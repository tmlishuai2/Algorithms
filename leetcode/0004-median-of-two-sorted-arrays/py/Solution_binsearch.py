# Accepted
class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        if m > n:
            m, n, nums1, nums2 = n, m, nums2, nums1
        
        long = (m + n + 1) // 2
        lo = 0
        hi = m
        while lo <= hi:
            i = (lo + hi) // 2
            j = long - i
            if i > 0 and nums2[j] < nums1[i-1]:
                hi = i - 1
            elif i < m and nums1[i] < nums2[j-1]:
                lo = i + 1
            else:
                if i == 0:
                    left_max = nums2[j-1]
                elif j == 0:
                    left_max = nums1[i-1]
                else:
                    left_max = max(nums1[i-1], nums2[j-1])
                
                if (m + n) % 2 == 1:
                    return left_max
                
                # right_min
                if i == m:
                    right_min = nums2[j]
                elif j == n:
                    right_min = nums1[i]
                else:
                    right_min = min(nums1[i], nums2[j])
                    
                return (left_max + right_min) / 2.0