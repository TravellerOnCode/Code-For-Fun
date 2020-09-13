//to create a Single Linked List and add elements to it
//#include <bits/stdc++.h> 
#include <stdio.h>
using namespace std; 

class Node
{
    public:
        int data;
        Node* next;
}

int main()
{
    int N,item;
    cout << "Enter the value of N: ";
    cin >> N;
    Node *root = NULL;

    for (int i=0;i<N;i++)
    {
        cout << "Enter the value of N: ";
        cin >> item;
    
        Node *temp = new Node(item);
        temp->next = root;
        head = temp;
    }
    for (int i=0;i<N;i++)
    {
    }

    


    return 0;
}
