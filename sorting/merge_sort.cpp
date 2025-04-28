#include <iostream>
using namespace std;
void conqure(int arr[], int l, int mid, int h)
{
    int temp[7];
    int k = 0;

    int i = l;
    int j = mid + 1;
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= h)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = 0; p < k; p++)
    {
        arr[l + p] = temp[p];
    }
}
void divide(int arr[], int l, int h)
{
    int mid = l + ((h - l) / 2);
    if (l < h)
    {
        divide(arr, l, mid);
        divide(arr, mid + 1, h);
        conqure(arr, l, mid, h);
    }
}
void printArray(int arr[])
{
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{

    int size;
    cout << "array lenght = ";
    cin >> size;
    int arr[size];
    // unsorted array
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    // sorted array
    divide(arr, 0, 6);
    printArray(arr);
}