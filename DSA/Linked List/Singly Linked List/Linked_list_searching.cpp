// Singly linked list searching


#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Linked_List
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

    int search(Node* head, int value)
    {
        Node* p = head;
        int count=0;

        while (p != NULL)
        {
            if(p->data == value)
            {
                return count;
            }
            p = p->next;
            count++;
        }
        return -1;
    }
};

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    // head = (Node *)malloc(sizeof(Node));
    // second = (Node *)malloc(sizeof(Node));
    // third = (Node *)malloc(sizeof(Node));
    // fourth = (Node *)malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = NULL;

    Linked_List lmao;

    cout<<"The elements are: "<<endl;
    lmao.traverse(head);
    cout<<endl;

    int searchResult = lmao.search(head, 30);
    if(searchResult != -1)
    {
        cout<<"The element is found at: "<<searchResult <<endl;
    }
    else
    {
        cout << "The element is not found." << endl;
    }

    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}