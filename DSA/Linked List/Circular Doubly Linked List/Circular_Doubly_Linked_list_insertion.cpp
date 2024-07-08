// Circular Doubly Linled List insertion

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:

        int data;
        Node* next;
        Node* prev;
};

class Linked_List
{   
    public:

    void traverse(Node* head)
    {
        if(head == NULL)
        {
            cout<<"Linked List is Empty"<<endl;
            return;
        }

        Node* ptr = head;

        do 
        {
            cout<<"Element is: "<< ptr->data <<endl;
            ptr = ptr->next;
        } while (ptr != head);
    }

    Node* insert_at_begin(Node* head,int data)
    {
        // Node* ptr = (Node *)malloc(sizeof(Node));
        Node* ptr = new Node;
        ptr->data = data;
        // ptr->next = ptr->prev = ptr;                // this means next and prev pointers are pointing to the same node since there are no other nodes in the list
    
        Node* p = head;
        
        while(p->next != head)
        {       
            p = p->next; 
        }
        ptr->next = head;
        p->next = ptr;
        head = ptr;

        return head;
    }

    Node* insert_at_end(Node* head, int data)
    {
        Node* ptr = new Node;
        ptr -> data = data;
        // ptr->next = ptr->prev = ptr;                // this means next and prev pointers are pointing to the same node since there are no other nodes in the list

        Node* p = head;

        while(p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next = head;
        head->prev = ptr;

        return head;
    }

    Node* insert_after_node(Node* head, Node* prevnode, int data)
    {
        // Node* ptr = (Node*) malloc(sizeof(Node));
        Node* ptr = new Node;
        ptr -> data = data;
        // ptr->next = ptr->prev = ptr;                // this means next and prev pointers are pointing to the same node since there are no other nodes in the list


        ptr-> next = prevnode -> next;
        prevnode-> next = ptr;
        
        return head;
    }

    Node* insert_at_index(Node* head, int data, int index)
    {
        // Node* ptr = (Node*) malloc(sizeof(Node));
        Node* ptr = new Node;
        Node* p = head;
        // ptr->next = ptr->prev = ptr;                // this means next and prev pointers are pointing to the same node since there are no other nodes in the list
       
        ptr -> data = data;
        int i=0;

        while(i != index-1)
        {
            p = p -> next;
            i++;
        }
        ptr -> next = p->next;
        p->next = ptr;
        ptr->prev = p;
            
        return head;
    }
};

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    head->data = 10;
    head->prev = fourth;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data=30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = head;

    Linked_List lmao;

    cout<<"Elements before insertion: "<<endl;
    lmao.traverse(head);
    cout<<endl;

    cout << "Elements after insertion at first: " << endl;
    head = lmao.insert_at_begin(head, 75);
    lmao.traverse(head);
    cout<<endl;

    cout<<"Elements after insertion at end: "<<endl;
    head = lmao.insert_at_end(head, 85);
    lmao.traverse(head);
    cout<<endl;

    cout<<"Elements after insertion after node: "<<endl;
    head = lmao.insert_after_node(head,third,90);
    lmao.traverse(head);
    cout<<endl;

    cout<<"Elements after insertion after index: "<<endl;
    head = lmao.insert_at_index(head,100,3);
    lmao.traverse(head);
    cout<<endl;

    delete fourth;
    delete third;
    delete second;
    delete head;
    
    return 0;
}