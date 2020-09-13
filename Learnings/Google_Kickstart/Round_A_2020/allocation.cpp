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
        //sort(a+1,a+n+1);  //nlog n
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            if (b>=a[i])
            {
                ans++;
                b = b - a[i];
            }
        }
        cout << "Case #" << tc << ": " << ans << endl;

    }
    return 0;
}