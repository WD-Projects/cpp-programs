#include <iostream>
using namespace std;
void bubbleSort(int a[], int j, int high)
{
    while (j < high - 1)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j + 1], a[j]);
            j++;
        }
        else
        {
            j++;
        }
        if (j == high - 1)
        {
            high--;
            j = 0;
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
    bubbleSort(a, 0, size);
    printArray(a, size);
}