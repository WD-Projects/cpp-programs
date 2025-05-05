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
    cout << "Doing forward travarse for the circular doubly linklist:" << endl; 
    bool firstnode = true;
    while (cur != head || firstnode)
    {
        firstnode = false;
        cout << cur->data << endl;
        cout << cur << endl;
        cur = cur->next;
    }
} 

void ReverseTravarse(node *head, node *temp4)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    cout << "Doing reverse travarse for the circular doubly linklist:" << endl;
    bool lastnode = true;
    while (temp != temp4 || lastnode)
    {
        lastnode = false;
        cout << temp->data << endl;
        cout << temp << endl;
        temp = temp->prev;
    }
}

int main()
{
    node *head = CreateNewNode(6);
    node *temp1 = CreateNewNode(7);
    node *temp2 = CreateNewNode(8);
    node *temp3 = CreateNewNode(9);
    node *temp4 = CreateNewNode(10);

    head->prev = temp4;
    head->next = temp1;

    temp1->prev = head;
    temp1->next = temp2;

    temp2->prev = temp1;
    temp2->next = temp3;

    temp3->prev = temp2;
    temp3->next = temp4;

    temp4->prev = temp3;
    temp4->next = head;

    ForwardTravarse(head);
    ReverseTravarse(head, temp4);
}
