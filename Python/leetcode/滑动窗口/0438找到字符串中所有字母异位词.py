"""
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。

字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。

说明：

字母异位词指字母相同，但排列不同的字符串。
不考虑答案输出的顺序。
"""

from collections import defaultdict

class Solution:
    def findAnagrams(self, s, p):
        if len(s) == 0 or len(p) == 0:
            return []
        res = []
        mem = defaultdict(int)
        needs = defaultdict(int)
        for c in p: 
            mem[c] += 1
            needs[c] += 1
        p_len = len(p)
        s_len = len(s)
        left = right = 0
        t_len = p_len
        for right, c in enumerate(s):
            if mem[c] > 0: 
                t_len -= 1
            mem[c] -= 1
            
            if t_len == 0: #找到满足的窗口
                res.append(left)
            #滑动窗口
            #开始时，长度不满足，接着右移右窗口
            if right - left + 1 < p_len:
                continue
            
            #长度满足，右移左窗口
            if mem[s[left]] >= 0:
                t_len += 1
            mem[s[left]] += 1
            left += 1

        print("s:", s, "p:", p, "res:", res)
        return res
            




            



#测试用例
s = Solution()
s.findAnagrams("", "")
s.findAnagrams("a", "a")
s.findAnagrams("aaaaaa", "a")
s.findAnagrams("aaaaaa", "aa")
s.findAnagrams("bca", "ab")
s.findAnagrams("ecbadxabcghdefeabcd", "abcde")


        