#include <iostream>
using namespace std;
struct Queue
{
    int queue_size;
    int front;
    int rear;
    int occupaid;
    int *items;
};
Queue *createqueue(int capacity)
{
    Queue *pt = new Queue;
    pt->queue_size = capacity;
    pt->front = 0;
    pt->rear = 0;
    pt->occupaid = 0;
    pt->items = new int[capacity];
    return pt;
}
int isFull(Queue *pt)
{
    if (pt->occupaid == pt->queue_size)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Queue *pt)
{
    if (pt->occupaid == 0)
    {
        return 1;
    }
    return 0;
}
void enqueue(Queue *pt, int data)
{
    if (isFull(pt))
    {
        cout << "Queue is full" << endl;
        return;
    }
    pt->items[pt->rear] = data;
    cout << "Enqueued value is" << " " << pt->items[pt->rear] << endl;
    pt->rear = (pt->rear + 1) % (pt->queue_size);
    pt->occupaid++;
}
void dequeue(Queue *pt, int data)
{
    if (isEmpty(pt))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    pt->front = (pt->front + 1) % (pt->queue_size);
    cout << "Dequeued value is" << " " << pt->items[pt->front - 1] << endl;
    pt->occupaid--;
}
int main()
{
    int i;
    Queue *q1 = createqueue(4);
    enqueue(q1, 1);
    enqueue(q1, 2);
    enqueue(q1, 3);
    enqueue(q1, 4);
    enqueue(q1, 5);
    // Before dequeued printing the values
    cout << "Before dequeuing the values are" << endl;
    for (i = 0; i < (q1->queue_size); i++)
    {
        cout << q1->items[i] << endl;
    }

    dequeue(q1, 1);
    enqueue(q1, 5);
    
    // After dequeued printing the values
    cout << "After dequeuing the values are" << endl;
    for (i = 0; i < (q1->queue_size); i++)
    {
        cout << q1->items[i] << endl;
    }
}
