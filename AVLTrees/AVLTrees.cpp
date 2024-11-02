//
// Created by maugv on 31/10/2024.
//

#include "AVLTrees.h"

// Constructor de la clase AVLTree, inicializa la raíz como nullptr.
template <typename T>
AVLTree<T>::AVLTree() : root(nullptr) {}

// Calcula la altura de un nodo dado. Si el nodo es nullptr, devuelve 0.
template <typename T>
int AVLTree<T>::height(AVLNode<T>* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

// Calcula el factor de balanceo de un nodo, es decir, la diferencia entre
// las alturas de los subárboles izquierdo y derecho.
template <typename T>
int AVLTree<T>::balanceFactor(AVLNode<T>* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

// Realiza una rotación a la derecha en el subárbol con raíz en y.
template <typename T>
AVLNode<T>* AVLTree<T>::rightRotate(AVLNode<T>* y) {
    AVLNode<T>* x = y->left;
    AVLNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;  // Nueva raíz después de la rotación.
}

// Realiza una rotación a la izquierda en el subárbol con raíz en x.
template <typename T>
AVLNode<T>* AVLTree<T>::leftRotate(AVLNode<T>* x) {
    AVLNode<T>* y = x->right;
    AVLNode<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;  // Nueva raíz después de la rotación.
}

// Inserta una clave en el árbol AVL de forma recursiva, balanceando el árbol si es necesario.
template <typename T>
AVLNode<T>* AVLTree<T>::insert(AVLNode<T>* node, T key) {
    if (node == nullptr)
        return new AVLNode<T>(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;  // Duplicados no permitidos en el árbol AVL.

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    // Realiza las rotaciones necesarias para mantener el balance del árbol
    if (balance > 1 && key < node->left->key)         // Caso Left Left
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)       // Caso Right Right
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {       // Caso Left Right
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {     // Caso Right Left
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Elimina un nodo con la clave dada y rebalancea el árbol si es necesario.
template <typename T>
AVLNode<T>* AVLTree<T>::deleteNode(AVLNode<T>* root, T key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode<T>* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVLNode<T>* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + std::max(height(root->left), height(root->right));
    int balance = balanceFactor(root);

    // Realiza las rotaciones necesarias para mantener el balance del árbol
    if (balance > 1 && balanceFactor(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && balanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && balanceFactor(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && balanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Encuentra el nodo con el valor mínimo en el subárbol dado.
template <typename T>
AVLNode<T>* AVLTree<T>::minValueNode(AVLNode<T>* node) {
    AVLNode<T>* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

// Realiza un recorrido en orden del árbol e imprime cada nodo.
template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* root) {
    if (root != nullptr) {
        inorder(root->left);
        std::cout << root->key << " ";
        inorder(root->right);
    }
}

// Busca un elemento en el árbol AVL de forma recursiva.
template <typename T>
bool AVLTree<T>::search(AVLNode<T>* root, T key) {
    if (root == nullptr)
        return false;
    if (root->key == key)
        return true;
    if (key < root->key)
        return search(root->left, key);
    return search(root->right, key);
}

// Inserta una clave en el árbol AVL llamando a la función recursiva de inserción.
template <typename T>
void AVLTree<T>::insert(T key) { root = insert(root, key); }

// Elimina una clave en el árbol AVL llamando a la función recursiva de eliminación.
template <typename T>
void AVLTree<T>::remove(T key) { root = deleteNode(root, key); }

// Busca una clave en el árbol AVL llamando a la función recursiva de búsqueda.
template <typename T>
bool AVLTree<T>::search(T key) { return search(root, key); }

// Imprime el árbol AVL en orden.
template <typename T>
void AVLTree<T>::printInorder() {
    inorder(root);
    std::cout << std::endl;
}
