class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        # sorted하면 애너그램 단어들은  다 똑같이 취급함
        # 그 애너그램 단어를 키로잡고 서로다른 여러개의 밸류를 잡기. 리스트로
        # 이때 딕셔너리에 여러가지 밸류 넣을때는 어펜드해야됌.
        dictionary = {}

        for i in range(len(strs)) :
            key = "".join(sorted(strs[i]))
            if key in dictionary :
                dictionary[key].append(strs[i])
            else :
                dictionary[key] = [strs[i]]
        return list(dictionary.values())