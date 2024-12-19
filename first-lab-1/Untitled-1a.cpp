#include <iostream>
using namespace std;

int main() {  // 
    // Create an array of 10 doubles
    double array[10] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};  // "Double" -> "double"

    // Print the contents of the array
    cout << "Array contents:" << endl;  
    for (int i = 0; i < 10; ++i) {  // 
        cout << "array[" << i << "] = " << array[i] << endl;
    }

    // Get the address of the beginning of the array
    double* startAddress = array;  // 

    // Print the address and the distance of each element
    cout << "\nElement addresses and distances from start:" << endl;
    for (int i = 0; i < 10; ++i) {  // "For" -> "for"
        cout << "Address of array[" << i << "] = " << (startAddress + i) 
             << ", Distance = " << i << " doubles" << endl;
    }

    return 0;  
}

