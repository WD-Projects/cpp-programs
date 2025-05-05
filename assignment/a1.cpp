#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next, *prev;
};

node *CreateNewNode(int value)
{
    node *newnode = new node;
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = nullptr;
    return newnode;
}

void ForwardTravarse(node *head)
{
    node *cur = head;
    cout << "Doing forward travarse for the doubly linklist:" << endl;
    while (cur != nullptr)
    {
        cout << cur->data << endl;
        cout << cur << endl;
        cur = cur->next;
    }
}

void ReverseTravarse(node *head)
{
    node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cout << "Doing reverse travarse for the doubly linklist:" << endl;
    while (cur != nullptr)
    {
        cout << cur->data << endl;
        cout << cur << endl;
        cur = cur->prev;
    }
}

int main()
{
    node *head = CreateNewNode(1);
    node *temp1 = CreateNewNode(2);
    node *temp2 = CreateNewNode(3);
    node *temp3 = CreateNewNode(4);
    node *temp4 = CreateNewNode(5);

    head->prev = nullptr;
    head->next = temp1;

    temp1->prev = head;
    temp1->next = temp2;

    temp2->prev = temp1;
    temp2->next = temp3;

    temp3->prev = temp2;
    temp3->next = temp4;

    temp4->prev = temp3;
    temp4->next = nullptr;

    ForwardTravarse(head);
    ReverseTravarse(head);
}
