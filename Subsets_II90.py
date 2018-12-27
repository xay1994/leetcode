class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """    
        res = []
        nums.sort()
        self.dfs(nums, 0, [], res)
        return res
    
    def dfs(self, nums, index, path, res):
        res.append(path)
        for i in xrange(index, len(nums)):
            if i > index and nums[i] == nums[i-1]:
                continue
            self.dfs(nums, i+1, path+[nums[i]], res)


or

class Solution:
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[ ]]
        nums.sort()
        size = 0
        for i in range(len(nums)):
            j = size if i > 0 and (nums[i] == nums[i-1]) else 0
            size = len(res)
            while j < size:
                temp = copy.copy(res[j])
                temp.append(nums[i])
                res.append(temp)
                j += 1    
        return res
