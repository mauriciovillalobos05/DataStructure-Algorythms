#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& vec, int target) {
    int low = 0;
    int high = vec.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return mid;
        } else if (vec[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // Si el target no se encuentra en el vector
}

int main() {
    std::vector<int> vec = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int target = 12;

    int result = binarySearch(vec, target);
    
    if (result != -1) {
        std::cout << "El número " << target << " se encuentra en el índice " << result << "." << std::endl;
    } else {
        std::cout << "El número " << target << " no se encuentra en el vector." << std::endl;
    }

    return 0;
}
