class Solution:
    def maxArea(self, height: List[int]) -> int:
        # 넓이는 min(left, right) * (right - left)
        # 최대가 되려면 min 쪽을 움직여야돼
        x, y = 0, len(height) - 1
        max_sum = 0
        
        while x < y :
            sum = min(height[x], height[y]) * (y - x)
            max_sum = max(sum, max_sum)

            if height[x] < height[y] :
                x += 1
            elif height[x] > height[y] :
                y -= 1
            else :
                x += 1
        return max_sum
        
