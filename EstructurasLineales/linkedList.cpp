#include <iostream>

struct Node{
    int data;
    Node* next;
};

void addNode(Node* &head,int value){
    Node* newNode= new Node();
    newNode->data=value;
    newNode->next=nullptr;

    if(head==nullptr){
        head=newNode;
    }
    else{
        Node* temp=head; //crear una variable temporal que almacene el current head, head siempre debe ser constante
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newNode;
    }
};

void deleteNode(Node* &head,int value){
    if(head==nullptr){
        return;
    }
    if(head->data==value){
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }

    Node* temp=head;
    while(temp->next!=nullptr && temp->next->data!=value){
        temp=temp->next;
    }
    if(temp->next==nullptr){
        return;
    }
    Node* nodeDelete=temp->next;
    temp->next=temp->next->next;
    delete nodeDelete;

};

void showList(Node* &head){
    Node* temp = head;
    while(temp!=nullptr){
        std::cout<<temp->data<<"->";
        temp=temp->next;
    }
}

int main(){
    Node* list=nullptr;
    addNode(list, 40);
    addNode(list,10);
    addNode(list,890);
    showList(list);

    return 0;
}