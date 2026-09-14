class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        res = []  
        keys = []  
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1

            found = False
            for i, key in enumerate(keys):
                if count == key:
                    res[i].append(s)
                    found = True
                    break

            if not found:
                keys.append(count[:])  
                res.append([s])

        return res