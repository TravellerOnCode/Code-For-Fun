/*
Problem
There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

What is the maximum number of houses you can buy?
*/


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e5 + 5;

int n,b;
int a[N];

void solution()
{

}

int32_t main()
{
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        tc++;
        cin >> n >> b;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
        }


        //write the logic here
        //call solution
        

        cout << "Case #" << tc << ": " << ans << endl;

    }
    return 0;
}