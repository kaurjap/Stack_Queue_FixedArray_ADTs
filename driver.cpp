#include <iostream>
#include "Array.h"

// function prototypes
template <typename T>
void print (const Array <T> & arr); // to print an array object

int main (int argc, char * argv [])
{
    Array <int> a1;
    Array <int> a2 (5);
    Array <int> a3 (4, 1);
    Array <int> a4 (a3);

    print (a1);
    print(a2);
    print (a3);
    print (a4);

    a1 = a4;
    print (a1);

    if (a1 == a4 && a3 == a4) {
        std::cout << "true where true" << std::endl; 
    }
    if (a2 != a4) {
        std::cout << "false where false" << std::endl;
    }

    a4[0] = 9;
    int get = a4[0];
    std::cout << "\nget method gives: " << get << std::endl;
    print (a4);

    int index = a4.find(9);
    std::cout << "index of 9 should be 0: " << index << std::endl; 

    index = a4.find(1,1); // should be 1
    std::cout << "index: " << index << std::endl;

    index = a4.find(9,1); // -1
    std::cout << "index: " << index << std::endl;

    /* exceptions
    index = a4.find(5, 4);
    std::cout << "index: " << index << std::endl;
    a4[5];
    a4[6] = 3;
    a4.set(4, 6); // throw exception
    */

    a2.resize(3);
    a2.fill(2);
    print(a2);

    a3.resize(8);
    a3.fill(3);
    print(a3);

    return 0;
} // end main

template <typename T>
void print (const Array <T> & arr) {
    std::cout << "\n***** PRINT *****" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr.get(i) << ",";
        } // end for
        std::cout << "\ncurrent size: " << arr.size();
        std::cout << "\nmaximum size: " << arr.max_size() << std::endl;
} // end print