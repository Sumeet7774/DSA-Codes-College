// Doubly Linked List deletion

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

class Linked_List
{
public:
    void traverse(Node *ptr)
    {
        while (ptr != NULL)
        {
            cout << "Element is: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    Node *delete_at_begin(Node *head)
    {
        Node *ptr = head;
        head = head->next;
        head->prev = NULL;
        delete(ptr);

        return head;
    }

    Node* delete_at_end(Node* head)
    {
        Node* p = head;
        Node* q = head->next;
        int i = 0;

        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->prev = q;
        p->next = NULL;
        delete(q);
    
        return head;
    }

    Node* delete_at_index(Node* head, int index)
    {
        Node* p = head;
        Node* q = head->next;
        int i = 0;

        while (i < index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        q->next->prev = p;
        delete(q);

        return head;
    }

    Node* delete_after_node(Node* head, int value)
    {
        Node* p = head;
        Node* q = head->next;

        while (q->data != value && q->next != NULL)
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
        return head;
    }
};

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    Node *seventh = new Node;

    head->data = 10;
    head->prev = NULL;
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
    seventh->next = NULL;

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