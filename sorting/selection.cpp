#include <iostream>
using namespace std;
void selectionSort(int a[], int low, int high)
{
    int i = low;
    int min = i;
    int j = i + 1;
    while (i < high - 1)
    {
        while (a[j] < a[min])
        {
            min = j;
            j++;
        }
        if (j < high)
        {
            j++;
        }
        if (j == high)
        {
            swap(a[min], a[i]);
            i++;
            j = i + 1;
            min = i;
        }
    }
}
void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int size;
    cout << "array size = ";
    cin >> size;
    int a[size];
    for (int k = 0; k < size; k++)
    {
        cin >> a[k];
    }
    selectionSort(a, 0, size);
    printArray(a, size);
}