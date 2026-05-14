class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # 해시맵 딕셔너리
        dictionary = {}

        for index in range(len(nums)) :
            y = target - nums[index]
            if y in dictionary :
                return dictionary[y], index
            dictionary[nums[index]] = index
                
