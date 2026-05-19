class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        # g[i]는 아이들이 만족할 크기 
        # s[i]는 쿠키의 크기 
        # g[1, 2, 3] s[1, 1] 이면 1만 만족하니까 return 1
        # 일단 젤 작은 s[j]부터 줘버려야돼. 
        # 그리디의 핵심은 정렬 후 매칭
        i = 0
        j = 0
        g.sort()
        s.sort()
        if not g or not s :
            return 0
        while i < len(g) and j < len(s) :
            if s[j] >= g[i] :
                i += 1
            j += 1
        return i