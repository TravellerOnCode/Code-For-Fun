
//Using Binary Search Technique

class Solution {
    public boolean isPerfectSquare(int num) {
        
        long l,r,p,m;
        l = 1;
        r = num;
        
        while(l<=r)
        {
            m = (l+r)/2;
            
            p = m * m;
            if (p==num)
                return true;
            if (p > num)
                r = m - 1;
            else
                l = m + 1;
            
        }
        return false;  
    }
}