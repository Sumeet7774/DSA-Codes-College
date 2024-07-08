// Circular Doubly Linled List deletion

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
        if(head == NULL)                                // edge case
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

    Node *delete_at_begin(Node *head)
    {
        Node* ptr = head;
        Node* last = head -> prev;

        last -> next = head -> next;
        head = last -> next;
        head->prev = last;
        delete(ptr);

        return head;
    }
    Node* delete_at_end(Node* head)
    {
        Node* last = head -> prev;
        last -> prev -> next = head;
        head -> prev = last -> prev;
        
        delete(last);

        return head;
    }

    Node* delete_at_index(Node* head, int index)
    {
        Node* p = head;
        Node* q = head -> next;
        int i = 0;

        while(i < index - 1)
        {
            p = p -> next;
            q = q -> next;
            i++;
        }
        p -> next = q -> next;
        q -> next -> prev = p;
        
        delete (q);

        return head;
    }   

    Node* delete_after_node(Node* head, int value)
    {
        Node* p = head;
        Node* q = head -> next;

        while (q->data != value && q->next != head)
        {
            p = p->next;
            q = q->next;
        }

        if (q->data == value)
        {
            p->next = q->next;
            q->next->prev = p;
            delete(q);
        }
        else
        {
            cout<<"Value not found in list"<<endl;
        }
        return head;  
    }
};

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;
    Node* fifth = new Node;
    Node* sixth = new Node;
    Node* seventh = new Node;

    head->data = 10;
    head->prev = seventh;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = fourth;

    fourth->data = 40;
    fourth->prev = third;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->prev = fourth;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->prev = fifth;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->prev = sixth;
    seventh->next = head;

    Linked_List lmao;

    cout << "Before Deletion" << endl;
    lmao.traverse(head);
    cout << endl;

    cout << "After Deletion at begin: " << endl;
    head = lmao.delete_at_begin(head);
    lmao.traverse(head);
    cout << endl;

    cout << "After Deletion at end: " << endl;
    head = lmao.delete_at_end(head);
    lmao.traverse(head);
    cout << endl;

    cout << "After Deletion at index: " << endl;
    head = lmao.delete_at_index(head, 2);
    lmao.traverse(head);
    cout << endl;

    cout << "After Deletion after node with value: " << endl;
    head = lmao.delete_after_node(head, 30);
    lmao.traverse(head);
    cout << endl;

    delete seventh;
    delete sixth;
    delete fifth;
    delete fourth;
    delete third;
    delete second;
    delete head;



    return 0;
}