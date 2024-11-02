#ifndef AVLTREES_H
#define AVLTREES_H

#include <iostream>
#include <algorithm>

// Clase para representar un nodo en un árbol AVL
template <typename T>
class AVLNode {
public:
    T key;                     // Clave del nodo
    AVLNode* left;             // Puntero al nodo hijo izquierdo
    AVLNode* right;            // Puntero al nodo hijo derecho
    int height;                // Altura del nodo en el árbol

    // Constructor: Inicializa el nodo con una clave y altura inicial de 1.
    AVLNode(T k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Clase para representar el árbol AVL
template <typename T>
class AVLTree {
private:
    AVLNode<T>* root;          // Puntero a la raíz del árbol

    // Calcula la altura de un nodo
    int height(AVLNode<T>* node);

    // Calcula el factor de balanceo de un nodo (diferencia de altura entre sus hijos)
    int balanceFactor(AVLNode<T>* node);

    // Realiza una rotación a la derecha en el subárbol con raíz en y
    AVLNode<T>* rightRotate(AVLNode<T>* y);

    // Realiza una rotación a la izquierda en el subárbol con raíz en x
    AVLNode<T>* leftRotate(AVLNode<T>* x);

    // Inserta un nodo en el árbol de forma recursiva y realiza balanceo
    AVLNode<T>* insert(AVLNode<T>* node, T key);

    // Elimina un nodo del árbol de forma recursiva y realiza balanceo
    AVLNode<T>* deleteNode(AVLNode<T>* root, T key);

    // Encuentra el nodo con el valor mínimo en un subárbol dado
    AVLNode<T>* minValueNode(AVLNode<T>* node);

    // Imprime los elementos del árbol en orden (inorder traversal)
    void inorder(AVLNode<T>* root);

    // Busca un elemento en el árbol
    bool search(AVLNode<T>* root, T key);

public:
    // Constructor por defecto: Inicializa el árbol con raíz nula
    AVLTree();

    // Inserta un elemento en el árbol
    void insert(T key);

    // Elimina un elemento del árbol
    void remove(T key);

    // Busca un elemento en el árbol
    bool search(T key);

    // Imprime los elementos del árbol en orden
    void printInorder();
};

#endif
