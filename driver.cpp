#include <iostream>
#include "Array.h"

// function prototypes
template <typename T>
void print (const Array <T> & arr); // to print an array object

int main (int argc, char * argv [])
{
    Array <char> a1;
    print (a1);
    /*
    Array <char> a2 (5);
    Array <char> a3 (4, 'a');
    Array <char> a4 (a3);

    print (a1);
    print(a2);
    print (a3);
    print (a4);

    a1 = a4;
    std::cout << "\na1 after assignment to a4: " << std::endl;
    print (a1);
    */



    return 0;
} // end main

template <typename T>
void print (const Array <T> & arr) {
    std::cout << "\n***** PRINT *****" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr.get(i) << ",";
        } // end for
        std::cout << "\ncurrent size: " << arr.size();
        std::cout << "\nmaximum size: " << arr.max_size();
} // end print