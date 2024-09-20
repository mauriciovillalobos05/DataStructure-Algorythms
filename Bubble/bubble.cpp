#include <iostream>
#include <vector>

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(std::vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

int main() {
    std::vector<int> vector;
    int n;

    for (int i = 0; i < 7; i++) {
        std::cout << "Agrega la calificacion " << i + 1 << ":" << std::endl;
        std::cin >> n;
        std::cout << std::endl;
        vector.push_back(n);
    }

    bubbleSort(vector);

    for (int num : vector) {
        std::cout << num << std::endl;
    }

    std::cout << "La calificacion más baja es: " << vector[0] << std::endl;
    std::cout << "La calificacion más alta es: " << vector[vector.size() - 1] << std::endl;

    return 0;
}
