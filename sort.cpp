#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <algorithm>

int main() {
    int arr[] = {4, 5, 8, 3, 7, 1, 2, 6, 10, 9};
    std::sort(arr, arr+10);
    cout << "sort array by default (increasing):" << endl;
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    cout << std::endl;

    return 0;
}
