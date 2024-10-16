#include <iostream>

class Queue{
    private:
        int front;
        int rear;
        int size;
        int* queue;
    public:
        Queue(int capacity);
        bool isEmpty();
        bool isFull();
        void enqueue(int value);
        void dequeue();
        int frontValue();
        ~Queue();
};

Queue::Queue(int capacity){
    front = -1; // Indica que la cola esta vacia
    rear = -1;  // Indica que la cola esta vacia
    size = capacity; // Tamaño de la cola
    queue = new int[size]; // Crear la cola
}

bool Queue::isEmpty(){
    return front == -1; // Si front es -1, la cola esta vacia
}

bool Queue::isFull(){
    return rear == size - 1; // Si rear es igual al tamaño de la cola, la cola esta llena
}

void Queue::enqueue(int value){
    if(isFull()){
        std::cout << "Queue llena: " << std::endl;
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = value;
    std::cout << value << " enqueue to queue" << std::endl; // Agregar un valor a la cola
}

void Queue::dequeue(){
    if(isEmpty()){
        std::cout << "Queue vacia" << std::endl;
        return;
    }
    // Eliminar un valor de la cola
    front++;

    if(front > rear){
        front = -1;
        rear = -1;
    }
}

int Queue::frontValue(){
    if(isEmpty()){
        std::cout << "Queue vacia" << std::endl;
        return -1;
    }
    return queue[front];
}

Queue::~Queue(){
    delete[] queue;
}

int main(){
    Queue q(5);
    q.enqueue(1);
    q.enqueue(88);
    q.enqueue(55);

    q.dequeue();
    q.dequeue();

    std::cout << "Front value: " << q.frontValue() << " in the queue" << std::endl;

    return 0;
}