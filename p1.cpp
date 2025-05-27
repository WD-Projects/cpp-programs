// #include <iostream>
// using namespace std;
// int swapping(int arr[], int low, int high){
//     int i = low;
//     int pivot = arr[low];
//     int j = high;
//     while(i < j){
//         while(arr[i] <= pivot && i <= high){
//             i++;
//         }
//         while(arr[j] > pivot){
//             j--;
//         }
//         if(i < j){
//             swap(arr[i], arr[j]);
//         }
//         else{
//             swap(arr[low], arr[j]);
//         }
//     }
//     return j;
// }
// void divide(int arr[], int low, int high){
//     if(low < high){
//       int pivotIndex = swapping(arr, low, high);
//       divide(arr, low, pivotIndex - 1);
//       divide(arr, pivotIndex + 1, high);
//     }
// }
// void printArray(int arr[], int size){
//     for(int i = 0; i < size; i++){
//         cout << arr[i] << " ";
//     }
// }
// int main(){
//     int arr[6] = {23, 11, 34, 1, 0, 45};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     divide(arr, 0, size - 1);
//     printArray(arr, size);
// }



#include <iostream>
using namespace std;
void conquer(int arr[], int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[high - low + 1];
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(int p = 0; p < k; p++){
        arr[low + p] = temp[p];
    }
}
void divide(int arr[], int low, int high){
    int mid = low + ((high - low)/2);
    if(low < high){
        divide(arr, low, mid);
        divide(arr, mid + 1, high);
        conquer(arr, low, mid, high);
    }
}
void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}    
int main(){
    int arr[6] = {23, 11, 34, 1, 0, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    divide(arr, 0, size - 1);
    printArray(arr, size);
}