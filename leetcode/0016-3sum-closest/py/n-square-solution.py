class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        res = nums[0] + nums[1] + nums[2]
        dist = abs(target - res)
        
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            
            while j < k:
                sum_tmp = nums[i] + nums[j] + nums[k]
                if sum_tmp == target:
                    return sum_tmp
                if abs(sum_tmp - target) < dist:
                    dist = abs(sum_tmp - target)
                    res = sum_tmp
                if sum_tmp > target:
                    k -= 1
                else:
                    j += 1
                    
        return res