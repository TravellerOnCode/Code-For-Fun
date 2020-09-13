#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool compare(vector<int> arr1, vector<int> arr2,string p) 
    { 
        for (int i=0; i<p.length(); i++) 
            if (arr1[p.at(i)-97] != arr2[p.at(i)-97]) 
                return false; 
        return true; 
    } 
    vector<int> findAnagrams(string s, string p) {
        
        int l1,l2,i,j;
        vector<int> index;
        l1 = s.length();
        l2 = p.length();
        if (l1 == 0 || l2==0 || l2>l1)
            return index;
        
        vector<int> s1(26,0);
        vector<int> s2(26,0);
        
        for (i=0;i<l2;i++)
        {
            s2[p.at(i)-97]++;
            s1[s.at(i)-97]++;
        }
        i=0;
        if (compare(s1,s2,p))
            index.push_back(i);
            
        for (i=1;i<=l1-l2;i++)
        {
            s1[s.at(i-1)-97]--;
            s1[s.at(i+l2-1)-97]++;
            
            if (compare(s1,s2,p)){
                index.push_back(i);
            }
        }
        return index;
        
    }
};