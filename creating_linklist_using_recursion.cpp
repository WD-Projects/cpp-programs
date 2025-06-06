#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
void CreateLinkList(node *head, int value)
{
    if(value==20)
    {
        return;
    }
    node *tmp = new node;
    tmp->data = value;
    tmp->next = nullptr;
    node *cur = head;
    while (cur->next != nullptr)
    {
        cur = cur->next;
    }
    cur->next = tmp;
    CreateLinkList(head, ++value);
    return;
}
int main()
{
    node *head = new node;
    head->data = 5;
    head->next = nullptr;
    CreateLinkList(head, 6);
    node *tmp = head;
    while (tmp != nullptr)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    return 0;
}
