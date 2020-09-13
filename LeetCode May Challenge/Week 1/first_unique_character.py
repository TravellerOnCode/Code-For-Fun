class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        f = 0
        count = [0] * 26
        for i in s:
            index = ord(i) - 97
            count[index] = count[index] + 1
            
        for i in s:
            index = ord(i) - 97
            if (count[index] == 1):
                return f
            f = f + 1
            
            
        #print(count)
        
        return -1