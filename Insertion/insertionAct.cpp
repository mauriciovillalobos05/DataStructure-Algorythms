#include <iostream>
#include <vector>
#include <cmath>

void insertionSort(std::vector<int>& vec){
    int n=vec.size();
    for(int i=1;i<n;i++){
        int key=vec[i];
        int j=i-1;
        while(j>=0 && vec[j]>key){
            vec[j+1]=vec[j];
            j--;
        }
        vec[j+1]=key;
    }
}

bool esPrimo(int n) {
    if (n <= 1) return false; 
    if (n == 2 || n == 3) return true; 
    if (n % 2 == 0 || n % 3 == 0) return false; 

    for (int i = 5; i <= std::sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    std::vector<int> arr = {12, 5, 3, 7, 11, 4, 8, 13};

    insertionSort(arr);

    std::vector<int> primos;

    for(int num:arr){
        std::cout<<num<<" ";
    }

    std::cout<<std::endl;

    for (int num:arr){
        if(esPrimo(num)){
            primos.push_back(num);
        }
    }

    for(int num:primos){
        std::cout<<num<<" ";
    }
}