#include <iostream>

int main() {
    int capacity = 5;             
    int* number = new int[capacity]; 
    int entries = 0;

    while (true) {
        std::cout << "Numbers: " << std::endl;
        std::cin >> number[entries];

        if (std::cin.fail()) break; 
        entries++;

        if (entries == capacity) { 
            // Duplicar la capacidad del arreglo cuando está lleno
            capacity *= 2;
            int* temp = new int[capacity];

            // Copiar los elementos del arreglo original al nuevo
            for (int i = 0; i < entries; i++) {
                temp[i] = number[i];
            }

            delete[] number;  // Liberar la memoria del arreglo anterior
            number = temp;    // Apuntar al nuevo arreglo con mayor capacidad

            if(entries>capacity){
                std::cout<<"Warning: Exceeded Capacity"<<std::endl;
            }
        }
    }

    // Mostrar los números almacenados
    for (int i = 0; i < entries; i++) {
        std::cout << number[i] << std::endl;
    }

    delete[] number;  // Liberar la memoria asignada dinámicamente
}
