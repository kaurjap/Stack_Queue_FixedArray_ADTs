#include <iostream> 
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"


// function prototypes
template <typename T>
void print (const Array <T> & arr); // to print an array object

template <typename T, size_t N>
void print (const Fixed_Array <T, N> & arr); // to print Fixed_Array

template <typename T>
void print (Stack <T> stack);

void testArray();
void testFixedArray(); 
void testStack();


int main (int argc, char * argv [])
{
    testArray();
    // testFixedArray();
    // testStack();

    return 0;
} // end main


void testStack() {
    Stack <char> stack;
    // print (stack); // throws exception

    if (stack.is_empty()) {
        std::cout << "true where true\n";
    } 
    stack.push ('a');
    stack.push ('b');
    stack.push ('c');
    if (stack.is_empty() == false) {
        std::cout << "false where false\n";
    }
    print (stack);
    stack.pop ();
    print (stack);

    Stack <char> s2 (stack);
    print (s2);
    
    Stack <char> s3;
    print (s3);
    s3 = stack;
    print (s3);

    stack.clear();
    s2.clear();
    s3.clear();

    // print (stack); // throws exception
} // end testStack


void testFixedArray() {
    Fixed_Array <int, 5> a1;
    a1.fill(1);
    //print(a1);

    Fixed_Array <int, 5> a2 (a1); // calls the copy constructor
    //print (a2);

    Fixed_Array <int, 7> a4 (2); // fill with 1, also tests fill

    print (a1);
    print (a2);
    print (a4);


    Fixed_Array <int, 7> a5;
    a5 = a4; // calls assignment for same sized arrays
    print (a5);
    
} // end testFixedArray


void testArray() {
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

    // exceptions, catch the following
    try {
        index = a4.find(5, 4);
    } catch (const std::out_of_range & ex) {
        ex.what();
    }

    try {
        a4[5];
    } catch (const std::out_of_range & ex) {
        ex.what();
    }

    try {
        a4[6] = 3;
    } catch (const std::out_of_range & ex) {
        ex.what();
    }

    try {
        a4.set(4, 6);
    } catch (const std::out_of_range & ex) {
        ex.what();
    }
    

    a2.resize(3);
    a2.fill(2);
    print(a2);

    a3.resize(8);
    a3.fill(3);
    print(a3);
} // end testArray


template <typename T>
void print (const Array <T> & arr) {
    std::cout << "\n***** PRINT *****" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr.get(i) << ",";
        } // end for
        std::cout << "\ncurrent size: " << arr.size();
        std::cout << "\nmaximum size: " << arr.max_size() << std::endl;
} // end print


template <typename T, size_t N>
void print (const Fixed_Array <T, N> & arr) {
std::cout << "\n***** PRINT *****" << std::endl;
    for (size_t i = 0; i < arr.size(); i++) {
            std::cout << arr.get(i) << ",";
        } // end for
        std::cout << "\ncurrent size: " << arr.size();
        std::cout << "\nmaximum size: " << arr.max_size() << std::endl;
} // end print

template <typename T>
void print (Stack <T> stack) {
    std::cout << "\n------- STACK ---------\n";
    std::cout << "size: " << stack.size() << std::endl;
    for (size_t i = 0; i < stack.size(); i++) {
        std::cout << stack.top() << std::endl;
        if (i == stack.size() - 1) {
		stack.pop();
	} // end if
    } // end for
} // end print
