"""
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        if len(s) == 0:
            return 0
        maxlen = 1
        # 双指针 l r为窗口边界，窗口大小从1开始
        l = r = 0
        # 用dict window记录已经遍历的字符，遍历记录位置
        window = {}
        # 每次移动r一格，遍历到字符c，window[c] 存在，则遇到重复的字符
        for pos, c in enumerate(s):
            r = pos # 右移r一位
            if window.get(c, -1) == -1: #没有遇到重复的字符
                window[c] = pos
                strlen = r - l + 1
                if strlen > maxlen:
                    maxlen = strlen
            else: #遇到重复的字符，左移l
                cpos = window[c]
                while l <= cpos: # 清除l->cpos之间字符在window的痕迹
                    window[s[l]] = -1
                    l += 1 #移动到cpos后一位
                window[c] = pos # 更新c在window的记录
        return maxlen

# 测试用例
s = Solution()
# 参数测试
ret = s.lengthOfLongestSubstring("")
print("ret:", ret)
# 单一字符测试
ret = s.lengthOfLongestSubstring("a")
print("ret:", ret)
ret = s.lengthOfLongestSubstring("aaaaaaaa")
print("ret:", ret)
# 无重复字符
ret = s.lengthOfLongestSubstring("abcdefg")
print("ret:", ret)
# 正常有重复字符串
ret = s.lengthOfLongestSubstring("pwwkew")
print("ret:", ret)
ret = s.lengthOfLongestSubstring("pwwkewabcdpwcd")
print("ret:", ret)