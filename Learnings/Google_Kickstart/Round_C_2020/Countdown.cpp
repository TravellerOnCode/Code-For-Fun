/*
Problem
Avery has an array of N positive integers. The i-th integer of the array is Ai.

A contiguous subarray is an m-countdown if it is of length m and contains the integers m, m-1, m-2, ..., 2, 1 in that order. For example, [3, 2, 1] is a 3-countdown.

Can you help Avery count the number of K-countdowns in her array?
*/


//#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 5;

int n,b;
int a[N],d[N];

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
        int ans = 0,f=0,x=0;
        for (int i=1;i<=n;i++)
        {
            if (f==1)
            {
                if (a[i-1]-a[i]==1)
                {
                    x++;
                    if (x==b) ans++;
                }
                else
                {
                    f = 0;
                    x = 0;
                }
            }
            if (a[i] == b)
            {
                f = 1;
                x = 1;
            }
        }
        cout << "Case #" << tc << ": " << ans << endl;

    }
    return 0;
}