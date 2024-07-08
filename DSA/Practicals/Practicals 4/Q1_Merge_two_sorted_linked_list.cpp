// Write a program that takes two sorted lists as inputs and merge them into one sorted 
// list.
// For example, if the first linked list A is 5 =>10 =>15, and the other linked list B is 2 => 
// 3 => 20, then output should be 2 => 3 => 5 => 10 => 15 => 20.

#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
        Node* next;
        int data;
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

        Node* merge_linked_list(Node* head, Node* head2)
        {
            Node* ptr = head;
            Node* ptr2 = head2;

            while(ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }

            ptr -> next = ptr2;

            return head;    
        }
};

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    Node* head2 = new Node;
    Node* second2 = new Node;
    Node* third2 = new Node;
    Node* fourth2 = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data=30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    head2 -> data = 50;
    head2 -> next = second2;

    second2 -> data = 60;
    second2 -> next = third2;
    
    third2 -> data = 70;
    third2 -> next = fourth2;

    fourth2 -> data = 80;
    fourth2 -> next = NULL;
    
    Linked_List lmao;

    cout<<"Elements of first linked list before sorting: "<<endl;
    lmao.traverse(head);
    cout<<endl;

    cout<<"Elements of second linked list before sorting: "<<endl;
    lmao.traverse(head2);
    cout<<endl;

    cout<<"Elements after merging the two sorted linked list: "<<endl;
    lmao.merge_linked_list(head, head2);
    lmao.traverse(head);
    cout<<endl;

    delete fourth;
    delete third;
    delete second;
    delete head;

    delete fourth2;
    delete third2;
    delete second2; 
    delete head2;

    return 0;
}