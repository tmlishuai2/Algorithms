class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        length = len(height)
        left = 0
        right = length - 1 # [left:right+1]
        
        max_area = min(height[left], height[right]) * (right - left)
        
        while left < right:
            if height[left] <= height[right]:
                area = height[left] * (right - left)
                max_area = max(max_area, area)
                left += 1
            else:
                area = height[right] * (right - left)
                max_area = max(max_area, area)
                right -= 1
        
        return max_area