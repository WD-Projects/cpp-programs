#include <iostream>
using namespace std;
void insertionSort(int a[], int low, int high)
{
    for (int j = low + 1; j < high; j++)
    {
        int temp = a[j];
        int i = j - 1;
        while ((temp < a[i]) && i >= 0)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = temp;
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
    insertionSort(a, 0, size);
    printArray(a, size);
}