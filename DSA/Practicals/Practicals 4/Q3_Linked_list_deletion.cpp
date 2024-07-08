// Write a program to delete a node from the linked list. A node can be deleted from the 
// linked list using three ways: [Write code for all the three ways.]
// a. Delete from the beginning 
// b. Delete from the end
// c. Delete from the middle.

// Singly linked list deletion

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class linked_list
{
public:
    void traverse(Node* ptr)
    {
        while (ptr != NULL)
        {
            cout << "Element is: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    Node* delete_at_begin(Node* head)
    {
        Node* ptr = head;
        head = head->next;
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
            delete(q);
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

    // head = (Node *)malloc(sizeof(Node));
    // second = (Node *)malloc(sizeof(Node));
    // third = (Node *)malloc(sizeof(Node));
    // fourth = (Node *)malloc(sizeof(Node));
    // fifth = (Node *)malloc(sizeof(Node));
    // sixth = (Node *)malloc(sizeof(Node));
    // seventh = (Node *)malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = fifth;

    fifth->data = 50;
    fifth->next = sixth;

    sixth->data = 60;
    sixth->next = seventh;

    seventh->data = 70;
    seventh->next = NULL;

    linked_list monkey;
    cout << "Before Deletion" << endl;
    monkey.traverse(head);
    cout << endl;

    cout << "After Deletion at begin: " << endl;
    head = monkey.delete_at_begin(head);
    monkey.traverse(head);
    cout << endl;

    cout << "After Deletion at end: " << endl;
    head = monkey.delete_at_end(head);
    monkey.traverse(head);
    cout << endl;

    cout << "After Deletion at index: " << endl;
    head = monkey.delete_at_index(head, 2);
    monkey.traverse(head);
    cout << endl;

    cout << "After Deletion after node with value: " << endl;
    head = monkey.delete_after_node(head, 30);
    monkey.traverse(head);
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