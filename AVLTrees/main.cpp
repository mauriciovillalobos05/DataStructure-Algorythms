#include "AVLTrees.h"
#include "AVLTrees.cpp"

int main() {
    AVLTree<int> avl;

    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    std::cout << "Inorder del AVL tree: ";
    avl.printInorder();

    avl.remove(30);
    std::cout << "Inorder despues de eliminar 30 ";
    avl.printInorder();

    std::cout << "Hay un 25 en el arbol? " << (avl.search(25) ? "Si" : "No") << std::endl;
    std::cout << "Hay un 30 en el arbol?" << (avl.search(30) ? "Si" : "No") << std::endl;

    return 0;
}
