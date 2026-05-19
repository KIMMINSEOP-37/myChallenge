class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        # 각 손님들 오직 한개의 레몬에이드만 삼.
        # 다 5달러인데, 누구는 5, 10 ,20달러를 냄(bills).
        # 거스름돈을 줄 수 있으면 true  
        five = 0 # five달러 지폐의 갯수
        ten = 0
        twenty = 0
        for i in range(len(bills)) :
            if bills[i] // 5 == 1 :
                five += 1
            elif bills[i] // 5 == 2 :
                if five < 1 :
                    return False
                else :
                    ten += 1
                    five -= 1
            elif bills[i] // 5 == 4 : # 이게 15달러도 10달러부터 보내야돼. (5 + 5 + 5는 나중에 == 그리디)
                if ten >= 1 and five >= 1 :
                    ten -= 1
                    five -= 1
                elif five >= 3 :
                    five -= 3
                else :
                    return False
        return True
