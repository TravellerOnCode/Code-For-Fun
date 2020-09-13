class Solution {
    
    public void fill_image(int[][] image, int sr, int sc, int newColor,int R,int C,int prevcolor)
    {   
        // Base cases 
        if (sr < 0 || sr >= R || sc < 0 || sc >= C) 
            return; 
        if (image[sr][sc] != prevcolor) 
            return; 
  
        image[sr][sc] = newColor; 
  
        fill_image(image, sr+1, sc, newColor,R,C,prevcolor); 
        fill_image(image, sr-1, sc, newColor,R,C,prevcolor); 
        fill_image(image, sr, sc+1, newColor,R,C,prevcolor); 
        fill_image(image, sr, sc-1, newColor,R,C,prevcolor); 
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) 
    {
        Solution ob = new Solution();

        // if the previous color is not new then return original array
        if (image[sr][sc] != newColor)
            ob.fill_image(image,sr,sc,newColor,image.length,image[0].length,image[sr][sc]);
        return image;
    }
     
        
}