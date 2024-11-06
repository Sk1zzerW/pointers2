#include <iostream>

int* allocateArray(int size) {
    return new int[size];
}

void initializeArray(int* arr, int size, int value) {
    for (int i = 0; i < size; ++i) {
        arr[i] = value;
    }
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void deleteArray(int* arr) {
    delete[] arr;
}

int* addElement(int* arr, int& size, int element) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < size; ++i) {
        newArray[i] = arr[i];
    }
    newArray[size] = element;
    delete[] arr;
    size++;
    return newArray;
}
int* insertElement(int* arr, int& size, int element, int index) {
    int* newArray = new int[size + 1];
    for (int i = 0; i < index; ++i) {
        newArray[i] = arr[i];
    }
    newArray[index] = element;
    for (int i = index; i < size; ++i) {
        newArray[i + 1] = arr[i];
    }
    delete[] arr;
    size++;
    return newArray;
}

int* removeElement(int* arr, int& size, int index) {
    int* newArray = new int[size - 1];
    for (int i = 0; i < index; ++i) {
        newArray[i] = arr[i];
    }
    for (int i = index + 1; i < size; ++i) {
        newArray[i - 1] = arr[i];
    }
    delete[] arr;
    size--;
    return newArray;
}

int main() {
    int size = 5;
    int* arr = allocateArray(size);
    initializeArray(arr, size, 10);
    printArray(arr, size);

    arr = addElement(arr, size, 15);
    printArray(arr, size);

    arr = insertElement(arr, size, 20, 2);
    printArray(arr, size);

    arr = removeElement(arr, size, 1);
    printArray(arr, size);

    deleteArray(arr);
    return 0;
}
