// Doubly Linked List insertion

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* prev;
        Node* next;
};

class Linked_List
{
    public:
        void traverse(Node* ptr)
        {
            while(ptr != NULL)
            {
                cout<<"Element is: "<<ptr->data <<endl;
                ptr = ptr->next;
            }
        }

        Node* insert_at_begin(Node* head,int data)
        {
            // Node* ptr = (Node *)malloc(sizeof(Node));
            Node* ptr = new Node;
            ptr->next = head;
            ptr->prev = NULL;
            ptr->data = data;
            head = ptr;

            return head;
        }

        Node * insert_at_end(Node *head, int data)
        {
            // Node* ptr = (Node *)malloc(sizeof(Node));
            Node* ptr = new Node;
            Node* p = head;

            ptr -> data = data;

            while(p->next != NULL)
            {       
                p = p->next;  
            }
            p->next = ptr;
            ptr->prev = p;
            ptr->next = NULL;
            
            return head;
        }

        Node* insert_after_node(Node* head, Node* prevnode, int data)  
        {
            // Node* ptr = (Node*) malloc(sizeof(Node));
            Node* ptr = new Node;
            
            ptr -> data = data;

            ptr-> next = prevnode -> next;
            prevnode-> next = ptr;
            ptr->prev = prevnode;

            return head;
        }

        Node* insert_at_index(Node* head, int data, int index)
        {
            // Node* ptr = (Node*) malloc(sizeof(Node));
            Node* ptr = new Node;
            Node* p = head;
            
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
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data=30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = NULL;

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