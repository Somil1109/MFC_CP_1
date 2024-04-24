#include <iostream>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double timeSortingAlgorithm(void (*sortingAlgorithm)(int[], int), int arr[], int size) {
    auto start = high_resolution_clock::now();
    sortingAlgorithm(arr, size);
    auto stop = high_resolution_clock::now();
    return duration_cast<duration<double>>(stop - start).count();
}

int main() {
    int size;
    cout << "Enter array size: ";
    cin >> size;

    void (*sortingAlgorithms[])(int[], int) = {bubbleSort, selectionSort, insertionSort};
    string algorithmNames[] = {"Bubble Sort", "Selection Sort", "Insertion Sort"};

    cout << "Array size: " << size << endl;
        
    int* arr = new int[size];
    cout << "Enter " << size << " integers separated by space: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < sizeof(sortingAlgorithms) / sizeof(sortingAlgorithms[0]); i++) {
        int* tempArr = new int[size]; // Create a copy of the array for each sorting algorithm
        copy(arr, arr + size, tempArr);
        double timeTaken = timeSortingAlgorithm(sortingAlgorithms[i], tempArr, size);
        cout << "Time taken for " << algorithmNames[i] << ": " << timeTaken << " seconds" << endl;
        delete[] tempArr;
    }
    delete[] arr;

    return 0;
}
