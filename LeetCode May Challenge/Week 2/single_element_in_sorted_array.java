
class Solution {
    public int singleNonDuplicate(int[] nums) {
        
        int l,i,element,p_freq,prev;
        l = nums.length;
        prev = element = nums[0];
        p_freq = 1;
        for (i=1;i<l;i++)
        {
            if (nums[i] == prev)
                p_freq++;
            else
            {
                if (p_freq != 2)
                    element = prev;
                    
                p_freq = 1;
                
            }
            prev = nums[i];
        
        }
        if (p_freq == 1)
            element = nums[l-1];

        return element;
        
    }
}