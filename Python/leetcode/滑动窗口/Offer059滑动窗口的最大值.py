"""
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
"""

class Solution0(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        print("########################################")
        print("nums K:", nums, k)
        l_len = len(nums)
        if l_len <= 0: 
            return []
        if k == 1:
            return nums
        res = []
        maxNum = float('-inf')
        count = 0
        r = l = 0
        if k >= l_len:
            res.append(max(nums))
            return res
        while r < l_len:
            if nums[r] > maxNum:
                maxNum = nums[r]
                count = 1
            elif nums[r] == maxNum:
                count += 1
                
            # 未构成固定窗口，r继续右移
            if r - l + 1 < k:
                r += 1
                continue
            # 有固定窗口
            res.append(maxNum)
            # l右移
            if nums[l] == maxNum: #移除的是最大值
                count -= 1 
                if count == 0: # 刚好是唯一的最大值，重新计算max和count
                    maxNum = max(nums[l+1:r+1])
                    for n in nums[l+1:r+1]:
                        if n == maxNum:
                            count += 1
            l += 1 # 左移
            r += 1
        return res


from collections import deque

class Solution:
    def maxSlidingWindow(self, nums, k):
        q = deque(maxlen=k)
        temp = []
        for i in range(len(nums)):
            if i < k-1:
                q.append(nums[i])
                # print(q)
            else:
                q.append(nums[i])
                temp.append(max(q))
        return temp

class Solution2:
    def maxSlidingWindow(self, nums, k) :
        d = deque()
        res, n = [], len(nums)
        for i, j in zip(range(1 - k, n + 1 - k), range(n)):
            if i > 0 and d[0] == nums[i - 1]:
                d.popleft() # 删除 deque 中对应的 nums[i-1]
            while d and d[-1] < nums[j]:
                d.pop() # 保持 deque 递减
            d.append(nums[j])
            if i >= 0:
                res.append(d[0]) # 记录窗口最大值
        return res


# 测试用例
s = Solution()
#错误参数
res = s.maxSlidingWindow([], 1)
print("res:", res)
# k=1
res = s.maxSlidingWindow([1,2,3,-1], 1)
print("res:", res)
# k=3
res = s.maxSlidingWindow([1,3,-1,-3,5,3,6,7], 3)
print("res:", res)
res = s.maxSlidingWindow([3, 3, 2, 2, 2, 3, 6, 7], 3)
print("res:", res)

# k=数组长度
res = s.maxSlidingWindow([1,2,3], 3)
print("res:", res)
# k > 数组长度
res = s.maxSlidingWindow([1,2,3], 5)
print("res:", res)
# 数组长度为1
res = s.maxSlidingWindow([1], 1)
print("res:", res)