class Solution {
    public int findJudge(int N, int[][] trust) {
        
        int i,judge;
        int[] trust_judge_index =  new int[N];  // [i] = 0 if that person do not trust anybody
        int[] trust_person_index =  new int[N]; // [i] = N - 1 if everybody trusts that person
        
        for (i=0;i<trust.length;i++)
        {
            //System.out.println(trust[i][0]+"  "+trust[i][1]);
            trust_judge_index[trust[i][0]-1] ++;
            trust_person_index[trust[i][1]-1]++;    
        }
        
        judge = -1;
        for (i=0;i<N;i++)
        {
            if (trust_judge_index[i] == 0 && trust_person_index[i] == N - 1)
            {
                judge = i+1;
                break;
            }
        }  
        return judge;

    }
}