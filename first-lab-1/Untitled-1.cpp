#include <iostream>
using namespace std;
int main() {
    int n;
    // Get array size from the user
    cout << "Enter the size of the array: ";
    cin >> n;
    // Validate input
    if (n <= 0) {
        cerr << "Array size must be a positive number." << endl;
        return 1;
    }
    // Allocate memory for the array
    int* arr = new int[n]; 
    // Fill the array
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // Print the array contents, the address of the first element,
    // and the distance of each element from the beginning 
    cout << "Array contents:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "] = " << arr[i]
             << ", address: " << &arr[i] 
             << ", distance: " << reinterpret_cast<long long>(&arr[i]) - reinterpret_cast<long long>(arr) << " bytes" << endl;
    }
    // Free the memory allocated for the array
    delete[] arr;
    return 0;
}
