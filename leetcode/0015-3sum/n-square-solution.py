class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        numdict = {}
        visited = set()
        res = []
        for num in nums:
            if num in numdict:
                numdict[num] += 1
            else:
                numdict[num] = 1
 #hehe               
        nums_deduplicated = list(numdict.keys())
        nums2_set = set([x << 1 for x in nums_deduplicated])
        if 0 in numdict and numdict[0] >= 3:
            res.append([0, 0, 0])
        
        n = len(nums_deduplicated)
        for i in range(n):
            num_i = nums_deduplicated[i]
            if num_i != 0 and - num_i in nums2_set and numdict[-num_i//2] >= 2:
                res.append([num_i, -num_i//2, -num_i//2])
            for j in range(i + 1, n):
                num_j = nums_deduplicated[j]
                if 0 - num_i - num_j in visited:
                    res.append([num_i, num_j, -num_i - num_j])
            visited.add(num_i)
                
        return res
    
    #nilishaui
    #hehe
