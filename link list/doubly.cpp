#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
void NodeTravarsel(node *head)
{
    node *cur = head;
    while (cur != nullptr)
    {
        cout << cur->data << " " << endl;
        cout << &cur << endl;
        cur = cur->next;
    }
}
void ReverseTravarsel(node *head)
{
    node *cur1 = head;
    while (cur1->next != nullptr)
    {
        cur1 = cur1->next;
    }
    while (cur1 != nullptr)
    {
        cout << cur1->data << " " << endl;
        cout << &cur1 << " " << endl;
        cur1 = cur1->prev;
    }
}
int main()
{
    node *head = new node;
    node *tmp = new node;
    node *tmp1 = new node;

    head->data = 1;
    head->prev = nullptr;
    head->next = tmp;

    tmp->data = 2;
    tmp->next = tmp1;
    tmp->prev = head;

    tmp1->data = 3;
    tmp1->next = nullptr;
    tmp1->prev = tmp;
    NodeTravarsel(head);
    ReverseTravarsel(head);
}
