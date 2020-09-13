#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int x){
            this-> data = x;
            next = nullptr;
        }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    int size;
    Node* head;
    
    MyLinkedList() {
        size = 0;
        head = new Node(0);
        //head = NULL;
        //tail = NULL;
        
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index < 0 || index >= size) return -1;

        Node *temp = head;
        for(int i=0;i<=index;i++) // <=index because the first element is a dummy element
        {
            temp = temp -> next;
        }
        return (temp->data);
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* curr = head->next;
	    head->next = new Node(val);
	    head->next->next = curr;
	    size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* curr = head;
        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next = new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        Node* curr = head;
        for(int i = 0;i<index;i++)
            curr = curr->next;
        cout << "---" << "Index :" << index << "  Data: " << curr->data << endl;
        Node* temp = curr->next;
        curr->next = new Node(val);
        curr->next->next = temp;
        size++;
        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        Node* curr = head;
        for(int i = 0;i<index;i++)
            curr = curr->next;
        
        Node* temp = curr->next;
        curr->next = temp->next;
        size--;
        delete(temp);
        
    }
    void display()
    {
        Node* curr = head;
        cout << "Elements in the List ! " << endl;
        while(curr)
        {
            cout << curr->data << " ";
            curr = curr -> next;
        }
        cout << endl;
    }
};
/*
Input:
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
*/
int main()
{
    MyLinkedList* obj = new MyLinkedList();
    obj->display();
    obj->addAtHead(1);
    obj->display();
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    obj->display();
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    obj->display();
    cout << obj->get(1) << endl;

    
    
    //int param_1 = obj->get(0);
    
    obj->display();
    obj->addAtHead(1);
    obj->addAtHead(2);
    obj->addAtHead(3);
    obj->addAtHead(4);
    obj->display();
    obj->addAtTail(40);
    obj->addAtTail(50);
    obj->addAtTail(60);
    obj->addAtTail(70);
    obj->display();
    obj->addAtIndex(0,9);
    obj->addAtIndex(2,10);
    obj->display();
    cout << (obj->get(2)) << endl;
    cout << (obj->get(5)) << endl;
    cout << (obj->get(9)) << endl;
    
    obj->deleteAtIndex(4);
    obj->display();
    

}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */