//g++ create_sll_struct.cpp -o a
// ./a.exe


#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    void display()
    {
        node* temp = head;
        cout << "Elements in the Linked List ! \n";
        while(temp != NULL)
        {
            cout << temp->data << "  ";
            temp = temp -> next;
        }
        cout << "\n";
    }
};

int main()
{
    linked_list a;
    cout << "Hello ! \n";
    int n,item;
    cout << "Enter the number of elements : ";
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cout << "Enter element ! ";
        cin >> item;
        a.add_node(item);
        a.display();
    }
    //a.add_node(1);
    //a.add_node(2);
    a.display();
    return 0;
}