#include <iostream>
#include <vector>

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(std::vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // Ultimo elemento como pivote
    int i = low - 1;  // Índice del elemento más pequeño

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(std::vector<int> &arr, int low, int high) {
    if (low < high) {
        int pivote = partition(arr, low, high);  

        // Ordenar recursivamente las subpartes
        quickSort(arr, low, pivote - 1);
        quickSort(arr, pivote + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();

    quickSort(arr, 0, n - 1);

    std::cout << "Array ordenado: ";
    for (int a:arr){
        std::cout << a << " ";
    }
    return 0;
}
