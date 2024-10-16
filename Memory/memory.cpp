#include <iostream>

void increasePrice(double* price){
    *price*=1.2;
}

int main(){
    int number=10;
    int* pointer=&number;

    std::cout<<"dir puntero: "<<pointer<<std::endl;
    std::cout<<"valor puntero: "<<*pointer<<std::endl;

    //el operador & nos permite obtener la dirección de memoria
    std::cout<<"dir variable: "<<&number<<std::endl;

    //se permite realizar nuevas asignaciones una vez derreferenciado el puntero
    *pointer=20;
    std::cout<<"nuevo valor: "<<number<<std::endl;

    int x=10;
    int y=20;
    int* pointer1=&x;
    *pointer1 *=4;
    pointer1=&y;
    *pointer1 *=3;

    std::cout<<"pointer: "<<*pointer1<<std::endl;
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"y: "<<y<<std::endl;


    double price=100;
    increasePrice(&price);
    std::cout<<"price: "<<price<<std::endl;
    return 0;
}