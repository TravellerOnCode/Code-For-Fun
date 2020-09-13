class Solution {

    public String removeKdigits(String num, int k) {
        
        String S=num;
        int K = k,xx=0,i,j,index=0;
       if (S == null || K > S.length()) {  
        return "";  
      }  
        if (K == S.length())
            return "0";
      int add = S.length() - K;   
      char[] lowest = new char[add];  
      // convert the input into an array of digits  
      int[] digits = new int[S.length()];  
      for (i = 0; i < digits.length; i++) {  
        digits[i] = S.charAt(i) - '0';  
      }  
      index = 0;  
      int[] closest = new int[S.length()];  
      closest[digits.length - 1] = -1;  
      for (i = digits.length - 2; i >= 0; i--) {  
        j = i + 1;  
        while (j != -1 && digits[i] <= digits[j]) {  
          j = closest[j];  
        }  
        closest[i] = j;  
      }  
      for (i = 0; i < add; i++) {  
        j = index;  
        while (j != -1 && j <= (digits.length - (add - i))) {  
          lowest[i] = (char) (digits[j] + (int) '0');  
          index = j;  
          j = closest[j];  
        }  
        index++;  
      }  
      String result = String.valueOf(lowest);
        if (result.charAt(0)=='0'){
            for (i=0;i<result.length();i++)
            {
                if (result.charAt(i)!='0' || i==result.length()-1)
                {
                    xx=i;
                    break;
                }  
            }
            result = result.substring(xx,result.length());                
        }
        
      return result;

    }
}