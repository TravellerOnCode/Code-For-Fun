class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        
        count = {}
        l = len(nums)
        m = l/2
        for i in nums:
            
            k = count.keys()
            if i not in k:
                count.update({i:0})
                    
            count[i] = count[i] + 1
            
        print(count)
        maxx = 0
        e = -1
        for i in count:
            if count[i] > m and count[i] > maxx:
                maxx = count[i]
                e = i
        
        
        return e