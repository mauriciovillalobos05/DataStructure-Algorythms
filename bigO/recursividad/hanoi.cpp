#include <iostream>
using namespace std;

void torreDeHanoi(int n, char origen, char destino, char auxiliar) {
    // Caso base: solo hay un disco para mover
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }
    
    // Mover n-1 discos del origen al auxiliar usando el destino como poste intermedio
    torreDeHanoi(n - 1, origen, auxiliar, destino);
    
    // Mover el disco restante del origen al destino
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
    
    // Mover los n-1 discos del auxiliar al destino usando el origen como poste intermedio
    torreDeHanoi(n - 1, auxiliar, destino, origen);
}

int main() {
    int n;  // Número de discos
    cout << "Introduce el número de discos: ";
    cin >> n;
    
    // Llamar a la función para resolver la Torre de Hanoi
    torreDeHanoi(n, 'A', 'C', 'B');  // A: origen, C: destino, B: auxiliar
    
    return 0;
}
