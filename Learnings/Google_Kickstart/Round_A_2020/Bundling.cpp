#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e6 + 6;

typedef struct data
{
    data* child[26]; //array 
    int cnt;
}trie;

trie* root;
int n,k;
string a[N];

void insert(string &s) //always pass a string by reference no extra memory is created
{
    trie* cur = root;
    for (int i=0;i<s.size();i++)
    {
        char ch = s[i];
        int reqd = ch - 'A'; //map A-Z: 0 - 25
        if (!cur -> child[reqd]) //if not present insert this char
        {
            cur -> child[reqd] = new trie();
        }
        cur = cur -> child[reqd];
    }
    cur -> cnt++;
    
}

int ans = 0;

//perform DFS
void dfs(trie* cur, int lvl)
{
    for (int i=0;i<=25;i++)
    {
        if (cur -> child[i])
        {
            dfs(cur->child[i],lvl + 1);
            cur -> cnt += cur -> child[i] -> cnt;
        }
    }
    while(cur->cnt >= k) //if current node has >= K active words
    {
        cur -> cnt = cur -> cnt - k;
        ans = ans + lvl;
    }
}

int32_t main()
{
    int t;
    cin >> t;
    int tc=0;
    while(t--)
    {
        tc++;
        root = new trie();
        cin >> n >> k;
        for (int i=1;i<=n;i++)
        {
            cin >> a[i];
            insert(a[i]);
        }
        dfs(root, 0);
        cout << "Case #" << tc << ": " << ans << endl;
    }
    return 0;
}
