#include <iostream>

struct Node{
    int value;
    Node* next;
};

class Stack{
    private:
        Node* topNode; 
    public:
        Stack(): topNode(nullptr){};
        void push(int value){
            Node* newNode= new Node();
            newNode->value=value;
            newNode->next=topNode;
            topNode=newNode;
        }
        void pop(){
            if(isEmpty()){
               std::cout<<"El stack está vacío"<<std::endl;
               return; 
            }
            Node* temp=topNode;
            topNode=topNode->next;
            delete temp;
        }
        int top(){
            if(isEmpty()){
                std::cout<<"El stack está vacío"<<std::endl;
                return -1;
            }
            return topNode->value;
        }
        bool isEmpty(){
            return topNode==nullptr;
        }
};

int main(){
    Stack stack;
    stack.push(30);
    stack.push(50);
    stack.push(70);
    
    stack.pop();

    return 0;
}