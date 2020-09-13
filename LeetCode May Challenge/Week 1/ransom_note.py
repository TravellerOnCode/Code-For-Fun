class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        a = list(ransomNote)
        b = list(magazine)
        f = 1
        for i in a:
            if i in b:
                b.remove(i)
            elif i not in b:
                f = 0
                break
                
        if f == 0:
            return False
        else:
            return True
        