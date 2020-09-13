/* Dynamic Programming solution to find length of the  
   longest common substring */
#include<iostream> 
#include<string> 
#include <algorithm>
using namespace std; 

//#define int long long
#define endl "\n"

//const int N = 1e5 + 5;

//int table[N][N];

    
/* Returns length of longest common substring of X[0..m-1]  
   and Y[0..n-1] */
int LCSubStr(string X, string Y, int m, int n) 
{ 
    // Create a table to store lengths of longest 
    // common suffixes of substrings.   Note that 
    // LCSuff[i][j] contains length of longest 
    // common suffix of X[0..i-1] and Y[0..j-1].  
  
    //int LCSuff[m+1][n+1]; 
    int table[100][100];
    int result = 0;  // To store length of the  
                     // longest common substring 
  
    /* Following steps build LCSuff[m+1][n+1] in 
        bottom up fashion. */
    for (int i=0; i<=m; i++) 
    { 
        for (int j=0; j<=n; j++) 
        { 
  
            // The first row and first column  
            // entries have no logical meaning,  
            // they are used only for simplicity  
            // of program 
            if (i == 0 || j == 0) 
                table[i][j] = 0; 
  
            else if (X[i-1] == Y[j-1]) 
            { 
                table[i][j] = table[i-1][j-1] + 1; 
                result = max(result, table[i][j]); 
            } 
            else table[i][j] = 0; 
        } 
    } 
    return result; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    string s1="",s2="";
    
    cout << "Enter First String :";
    getline(cin,s1);
    cout << "Enter Second String :";
    getline(cin,s2);
    int m = s1.length(); 
    int n = s2.length(); 
  
    cout << "Length of Longest Common Substring is " 
         << LCSubStr(s1, s2, m, n); 
    return 0; 
} 
