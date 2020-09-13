#Creating the straight line equation and validating points

class Solution(object):
    
    def checkStraightLine(self, coordinates):
        """
        :type coordinates: List[List[int]]
        :rtype: bool
        """
        l = len(coordinates)
        for i in range(l-1):
            y1 = coordinates[i][0]
            y2 = coordinates[i+1][0]
            if y1 != y2:
                x1 = coordinates[i]
                x2 = coordinates[i+1]
                break
                
        
        slope = float((x1[1]-x2[1])/(x1[0]-x2[0]))
        f = 0
        for i in range(l):
            
            x = coordinates[i]
            
            y = slope * (x[0]-x1[0]) + x1[1]
            #print ("x = ", x[0] , "y = ", y , " y' = ", x[1])
            if (y == x[1]):
                f = f + 1
                
        if (f == l):
            return True
        
        return False
            
        
        
        