#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& vec, int ref) {
    for (int i=0;i<vec.size();i++){
        if (vec[i]>ref){
            return i;
        }
    }
    return -1;
}
int main() {
    std::vector<int> vec = {5, 2, 9, 7, 4, 6};
    int ref = 5;

    int result = linearSearch(vec, ref);
    
    if (result != -1) {
        std::cout << "Un número mayor a " << ref << " se encuentra en el índice " << result << "con un valor de" << vec[result]<<std::endl;
    } else {
        std::cout << "Un número mayor a" << ref << " no se encuentra en el vector." << std::endl;
    }

    return 0;
}
