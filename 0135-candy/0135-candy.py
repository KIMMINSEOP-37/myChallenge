class Solution:
    def candy(self, ratings: List[int]) -> int:
        # n명의 학생, 각각의 학생이 int ratings을 배정
        # 각각이 하나씩은 최소로 받아야함.
        # rating높으면 양쪽보다만 더 높은캔되면 돼.
        # return 너가 가지고있어야 할 전체 캔디 수
        count = [1] * (len(ratings))
        for i in range(len(ratings) - 1) :
            if ratings[i] < ratings[i + 1] : # 왼 < 오
                count[i + 1] = count[i] + 1
        for i in range(len(ratings) - 1, 0, -1) :
            if ratings[i] < ratings[i - 1] : # 왼 < 오
                count[i-1] = max(count[i-1], count[i] + 1) # 앞에서 뒤로 돌때 큰값이 있었으면 그걸 사용해야돼. 뒤에서 앞으로 가면서 두번 겹치는 거니까
        return sum(count)

        # rating작은놈이 캔디수가 늘어나면 그 위에 rating놈도 늘어야돼
        # 즉 count[i + 1] = count[i] + 1 전에놈에다가 1더해야돼