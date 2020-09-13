#include <bits/stdc++.h>
#include <stack>
using namespace std;

//#define int long long
#define endl "\n"

//const int N = 1e5 + 5;

//Display
void showstack(stack <char> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 

// Complete the isBalanced function below.
string isBalanced(string s) {

    stack<char> mystack;
    char ch = ' ';
    int i;
    for (i=0;i<s.size();i++)
    {
        ch = s[i];
        if (ch == '{' || ch == '(' || ch == '[')
        {
            mystack.push(ch);
            showstack(mystack);

        }  
        
        else if (!mystack.empty())
        {
            if (ch == '}' && mystack.top() == '{' && !mystack.empty())
            {
                mystack.pop();
                showstack(mystack);
            }
            else if (ch == ')' && mystack.top() == '(' && !mystack.empty())
            {
                mystack.pop();
                showstack(mystack);
            }
            else if (ch == ']' && mystack.top() == '[' && !mystack.empty())
             {
                mystack.pop();
                showstack(mystack);
            }
            else
                break;
        }
        else
            break;
    }

    cout << "-----";

    if (mystack.size() == 0 && i==s.size())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
        
    }

    fout.close();

    return 0;
}
