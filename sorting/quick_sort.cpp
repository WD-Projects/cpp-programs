#include <iostream>
using namespace std;
int swapping(int a[], int low, int high)
{
    int i = low;
    int j = high;
    int pivot = a[low];
    while (i < j)
    {
        while (a[i] <= pivot && i < high)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(a[i], a[j]);
        }
        else
        {
            swap(a[low], a[j]);
        }
    }
    return j;
}
void divide(int a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = swapping(a, 0, high);
        swapping(a, low, pivotIndex - 1);
        swapping(a, pivotIndex + 1, high);
    }
}
void printArray(int a[])
{
    for (int k = 0; k < 5; k++)
    {
        cout << a[k] << " ";
    }
}
int main()
{
    // unsorted array
    int size;
    cout << "array size = ";
    cin >> size;
    int a[size];
    for (int k = 0; k < size; k++)
    {
        cin >> a[k];
    }
    // sorted array
    divide(a, 0, size-1);
    // printing process after sorting
    printArray(a);
}