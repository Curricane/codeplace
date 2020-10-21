class Solution(object):
    def minWindow(self, s, t):
        def isContain(w, n):
            for c in n.keys():
                if w.get(c, 0) < n[c]:
                    return False
            return True
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        print("*****************", len(s), len(t), "*************")
        if len(s) == 0 or len(t) == 0:
            return ""

        #长度最小值
        minLen = float("inf")

        #最小结果
        minRes = ""

        #dict needs记录 T的所有字符组成
        needs = {}
        for c in t: needs[c] = needs.get(c, 0) + 1
        #dict window记录 窗口
        window = {}

        r, l = 0, 0
        lenS = len(s)
        
        # r到达限制
        while r < lenS:
            c = s[r]
            print("window is:", s[l:r+1])
            if c in needs:
                window[c] = window.get(c, 0) + 1
            while isContain(window, needs) and l <= r: #l 右移，并尝试优化    
                if minLen > r - l + 1:
                    minLen = r - l + 1
                    minRes = s[l:r+1]
                print("window is:", s[l:r+1])
                print("minRes is:", minRes, "l r is:", l, r)
                print()
                window[s[l]] = 0 if window.get(s[l], 0) == 0 else  window.get(s[l], 0) - 1
                l += 1
            #r右移，满足needs或超出限制为止
            r += 1    
        
        return minRes 


from collections import Counter
from collections import defaultdict


class Solution1:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        ans = s + s
        n = len(s)
        target = Counter(t)
        counter = defaultdict(lambda: 0)

        def contains(counter, target):
            if len(counter) < len(target):
                return False
            for k in counter:
                if k not in target or counter[k] < target[k]:
                    return False
            return True

        for r in range(n):
            if s[r] in target:
                counter[s[r]] += 1
            while l < n and contains(counter, target):
                if r - l + 1 < len(ans):
                    ans = s[l:r + 1]
                if s[l] in target:
                    counter[s[l]] -= 1
                l += 1
        return "" if ans == s + s else ans


class Solution3(object):
    def minWindow(self, s, t):
        mem = defaultdict(int)
        for c in t:
            mem[c] += 1
        t_len = len(t)

        minLeft, minRight = 0, len(s)
        left = 0

        for right, c in enumerate(s):
            # 把mem减到均为0，即t_len = 0则证明窗口包含需要的字符
            if mem[c] > 0:
                t_len -= 1
            mem[c] -= 1

            if t_len == 0:
                # 移动left指导刚好left指向的字符，是t中字符，且该字符刚好不富余
                while mem[s[left]] < 0: #mem中小于0的值，是右指针遍历过的不需要的字符，或者需要的字符有富余的
                    mem[s[left]] += 1 #有富余或者不是t中的字符，left接着往右移动
                    left +=1
                # 更新最小结果
                if right - left < minRight - minLeft:
                    minLeft, minRight = left, right
                mem[s[left]] += 1 #这移动前，个t中的字符，标记为少一次遍历，对应值+1
                t_len += 1
                left += 1
        return '' if minRight == len(s) else s[minLeft:minRight+1]
s = Solution()
s.minWindow("ADOBECODEBANC", "ABC")
s.minWindow("ADOBECODEBBOOAANCC", "ABC")