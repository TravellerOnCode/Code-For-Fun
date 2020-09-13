class Solution(object):
    def findComplement(self, num):
        """
        :type num: int
        :rtype: int
        """
        if num==0:
            return 1
        elif num==1:
            return 0
        bin_form = []
        num_new = num
        f=s=0
    
        while(num_new>0):
            q = num_new % 2
            num_new = num_new / 2
            
            bin_form.append(q)
            if q == 0:
                q = 1
            else:
                q = 0
                
            s = s + q*pow(2,f)
            
            f = f + 1
            
        #print(bin_form)
        return s