#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int id;
};

int swapping(student s[], int low, int high) {
    int i = low + 1;
    int j = high;
    student pivot = s[low];

    while (i <= j) {
        while ((s[i].name < pivot.name || (s[i].name == pivot.name && s[i].id < pivot.id)) && i <= high) {
            i++;
        }
        while ((s[j].name > pivot.name || (s[j].name == pivot.name && s[j].id > pivot.id)) && j > low) {
            j--;
        }
        if (i < j) {
            swap(s[i], s[j]);
        }
    }
    swap(s[low], s[j]);
    return j;
}

void divide(student s[], int low, int high) {
    if (low < high) {
        int pivotIndex = swapping(s, low, high);
        divide(s, low, pivotIndex - 1);
        divide(s, pivotIndex + 1, high);
    }
}

void printValues(student s[], int size) {
    for (int i = 0; i < size; i++) {
        cout << s[i].name << ' ' << s[i].id << endl;
    }
}

int main() {
    int size;
    cout << "Array size = ";
    cin >> size;
    student s[size];
    for (int i = 0; i < size; i++) {
        cout << "Student name = ";
        cin >> s[i].name;
        cout << "Student id = ";
        cin >> s[i].id;
    }
    divide(s, 0, size - 1);
    printValues(s, size);
    return 0;
}
