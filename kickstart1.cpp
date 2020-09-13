//#include <bits/stdc++.h> 
#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    int T,N,freq,i,j,f;
    cin >> T;
    while(T--)
    {
        cin >> N;
        vector<int> V(N,0);
        freq = 0;
        for (int i=0;i<N;i++)
        {
            cin >> V[i];
        }
        for (i=0;i<N;i++)
        {
            f=1;
            for (j=0;j<i;j++)
            {
                if (V[i] <= V[j])
                {
                    f=0;
                    break;
                }
            }
            if (f==1)
            {
                if (i==N-1)
                    freq = freq + 1;
                else if (V[i] > V[i+1])
                    freq = freq + 1;
                
            }
                
        }
        cout << freq << '\n';
    }
}