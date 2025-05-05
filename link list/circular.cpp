#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
void  CircularTravarsel(node*head){
    
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
    CircularTravarsel(head);
}
