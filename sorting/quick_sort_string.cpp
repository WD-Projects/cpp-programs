#include <iostream>
using namespace std;

int swapping(char a[], int low, int high)
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
    }
    swap(a[low], a[j]); // Place the pivot in the correct position
    return j;
}

void divide(char a[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = swapping(a, low, high);
        divide(a, low, pivotIndex - 1);    // Sort the left part
        divide(a, pivotIndex + 1, high);  // Sort the right part
    }
}

void printArray(char a[], int size)
{
    for (int k = 0; k < size; k++)
    {
        cout << a[k];
        if (k < size - 1)
        {
            cout << ",";
        }
    }
    cout << endl;
}

int main()
{
    string input;
    cout << "Enter characters separated by commas: ";
    cin >> input;

    // Count characters to determine the size of the array
    int size = 1; // At least one character
    for (char c : input)
    {
        if (c == ',')
        {
            size++;
        }
    }

    // Create and populate the array from the input string
    char a[size];
    int index = 0;
    for (char c : input)
    {
        if (c != ',')
        {
            a[index++] = c;
        }
    }

    // Sort the array
    divide(a, 0, size - 1);

    // Print the sorted array
    cout << "Sorted characters: ";
    printArray(a, size);

    return 0;
}
