class Solution:
    def findMin(self, nums: List[int]) -> int:
        # 오름차순으로 정렬하는데 몇번이 걸리냐 이거지.
        # min(nums)하면은 되긴하는데 이러면 O(n)이라서 의미가 없음 줄여야돼.
        # 이진탐색으로 풀어야 O(log n)

        # rotated sorted array 즉, 어느 한 지점(min)에서 앞뒤를 아에 바꾸는거야.
        # 출력은 배열에서 가장 최소값 : rotate하는 그지점 반환

        left, right = 0, len(nums) - 1
        # 무조건 left가 더커 값이
        while left < right :
            mid = (left + right) // 2
            if nums[mid] > nums[right]:   # 최솟값이 오른쪽
                left = mid + 1
            else:                          # 최솟값이 왼쪽(mid 포함)
                right = mid
            # 중요한게 숫자가 오름차순이니까 right랑 비교를 해야돼.
        return nums[left]