# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    global p
    global d
    def Node_details(self, root,parent,depth,node):
        if root == None: return 
        
        if (root.val == node): 
            self.p = parent
            self.d = depth
  
        self.Node_details(root.left,root.val,depth+1,node)
        self.Node_details(root.right,root.val,depth+1,node)
  
    def isCousins(self, root, x, y):
        """
        :type root: TreeNode
        :type x: int
        :type y: int
        :rtype: bool
        """
        
        self.Node_details(root,1,0,x)
        p_x,h_x = self.p,self.d
        self.Node_details(root,1,0,y)
        p_y,h_y = self.p,self.d
        #print(p_x,"  ",h_x)
        #print(p_y,"  ",h_y)
        if h_x == h_y and p_x != p_y:
            return True
        
        return False
        