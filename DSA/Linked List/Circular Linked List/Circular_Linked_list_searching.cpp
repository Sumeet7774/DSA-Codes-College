// Circular Linked list searching

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

    void traverse(Node* head)
    {
        Node* ptr = head;

        do
        {
           cout<<"Element is: "<<ptr->data <<endl;
           ptr = ptr -> next;
        } while (ptr != head);
    }

    int search(Node* head, int value)
    {
        Node* ptr = head;
        int count = 0;

        do
        {
            if(ptr->data == value)
            {
                return count;
            }
            ptr = ptr -> next;
            count++;

        } while(ptr != head);

        return -1;
    }
};


int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data=30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = head;

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
        cout << "The element is not found in the list." << endl;
    }

    delete fourth;
    delete third;
    delete second;
    delete head;

    return 0;
}