class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        # k를 인덱스별로 하나씩 다 해보면 되는거아님?
        window_sum = sum(nums[:k])   # 딱 한 번만 전체 합산
        max_sum = window_sum         # 초기 윈도우 sum 박기
        n = len(nums)

        for i in range(1, n - k + 1):
            window_sum = window_sum - nums[i-1] + nums[i+k-1]
            # 이미 구한 윈도우 섬에서 앞에거 빼고, 뒤에거 더해주기
            max_sum = max(max_sum, window_sum)
        return (max_sum / k)