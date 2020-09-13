class Solution(object):
    def numJewelsInStones(self, J, S):
        """
        :type J: str
        :type S: str
        :rtype: int
        """
        
        a=list(J)
        b=list(S)
        f = 0
        for i in b:
            if i in a:
                f = f + 1
                
        return f
        