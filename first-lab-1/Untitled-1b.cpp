#include <iostream>

using namespace std;

int main() {
    // Array of size 10 to store short integers
    short arr[10];

    // Input: Fill the array
    cout << "enter 10 short integers:"  << endl;
    for (int i = 0; i < 10; ++i) {
        cin >> arr[i];
    }

    // Output: Array contents, addresses, and distances
    cout << "\nArray contents, addresses, and distances:\n";
    for (int i = 0; i < 10; ++i) {
        cout << "arr[" << i << "] = " << arr[i] 
             << ", address: " << &arr[i]
             << ", distance: " << reinterpret_cast<long long>(&arr[i]) - reinterpret_cast<long long>(arr) 
             << " bytes" << endl;
    }

    return 0;
}


