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
void print (Stack <T> stack); // passed by value, so the actual stack values don't change

template <typename T>
void print (Queue <T> queue);

void testArray();
void testFixedArray(); 
void testStack();
void testQueue();


int main (int argc, char * argv [])
{
    testArray();
    testFixedArray();
    testStack();
    testQueue();
    return 0;
} // end main

void testQueue () {
    Queue <char> q1;
    q1.enqueue('a');
    q1.enqueue('b');
    q1.enqueue('c');
    q1.enqueue('d');
    print (q1);

    q1.dequeue ();
    print (q1);

    //copy constructor
    Queue <char> q2 (q1);
    print (q2);

    Queue <char> q3;
    try {
        q3.dequeue ();
    } catch (std::exception & ex) {
        std::cout << ex.what() << std::endl;
    } // end try-catch

    q3 = q1;
    print (q3);

    q1.clear();
    q2.clear();
    q3.clear();

    if (q1.is_empty() && q2.is_empty()) {
        if (q3.is_empty()) {
            std::cout << "all queues cleared";
        }
    }
} // end testQueue

void testStack() {
    Stack <char> stack;
    if (stack.is_empty()) {
        std::cout << "true when stack is empty\n";
    } 

    try {
	    std::cout << stack.top (); // throws empty exception
    } catch (const std::exception & ex) {
	    std::cout << ex.what() << std::endl;
    }

    stack.push ('a');
    stack.push ('b');
    stack.push ('c');
    if (stack.is_empty() == false) {
        std::cout << "false when stack isn't empty\n";
    }
    print (stack); // a,b,c
    std::cout << "top: " << stack.top() << std::endl; // returns c

    Stack <char> s2 (stack);
    print (s2);
    
    Stack <char> s3;  // size 0
    s3 = stack;
    print (s3);

    stack.clear();
    s2.clear();
    s3.clear();

    if (s2.is_empty()) {
        std::cout << "empty";
    }
    try {
        s2.pop();
    } catch (const std::exception & ex) {
        std::cout << ex.what();
    }
} // end testStack

void testFixedArray() {
    std::cout << "====== constructors, fill method =====\n";
    Fixed_Array <int, 5> a1;
    a1.fill(1);
    Fixed_Array <int, 5> a2 (a1); // calls the copy constructor
    Fixed_Array <int, 7> a4 (2); // fill constructor, also tests fill
    Fixed_Array <int, 7> a5; // empty
    Fixed_Array <int, 8> a6 (6); // fill with 6
    Fixed_Array <int, 2> a7; // empty


    print (a1);
    print (a2);
    print (a4);
    
    std::cout << "\n====  assignment & equality and inequality operators =====\n";
    a5 = a4; // calls assignment for same sized arrays
    print (a5);
    if (a5 == a4 && a1 == a2) {
	    std::cout << "true where true" << std::endl;
    }
    print (a6);
    if (a6 != a5 && a6 != a2) {
	    std::cout << "false where false" << std::endl;
    } 

    std::cout << "\n======= find methods =====\n";
    std::cout << "\n" << a1.find (1); // returns 0
    std::cout << "\n" << a1.find (2); // returns -1
    std::cout << "\n" << a1.find (1, 4); // returns 4

    std::cout << "\n======= access methods and [] operators=======\n";
    a1[0] = 9;
    std::cout << "\n" << a1.get (0); // returns 9
    a1.set(1, 8);
    std::cout << "\n" << a1[1]; // returns 8
    print (a1);
    a1.reverse ();
    print (a1);
} // end testFixedArray

void testArray() {
    Array <int> a1;
    Array <int> a2 (5);
    Array <int> a3 (4, 1);
    Array <int> a4 (a3);

    int i = a1.find (4);
    std::cout << "i :" << i << std::endl;
    
    print (a1);
    print (a2);
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
        std::cout << ex.what() << std::endl;
    }

    try {
        a4[5];
    } catch (const std::out_of_range & ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        a4[6] = 3;
    } catch (const std::out_of_range & ex) {
        std::cout << ex.what() << std::endl;
    }

    try {
        a4.set(4, 6);
    } catch (const std::out_of_range & ex) {
        std::cout << ex.what() << std::endl;
    }
    

    a2.resize(3);
    a2.fill(2);
    print(a2);

    a3.resize(8);
    a3.fill(3);
    print(a3);

    std::cout << "===== Reverse =====\n";
    a3.resize (7);
    // test reverse
    a3[0] = 1;
    a3.set(1, 2);
    a3[2] = 3;
    a3[3] = 4;
    a3[5] = 6;
    print (a3);
    a3.reverse ();
    print (a3);
} // end testArray


// print methods
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
    size_t size = stack.size();
    std::cout << "size: " << stack.size() << std::endl;
    for (size_t i = 0; i < size; ++i) {
        std::cout << stack.top() << std::endl;
        stack.pop();
    } // end for
} // end print

template <typename T>
void print (Queue <T> queue) {
    std::cout << "\n---- QUEUE --------\n";
    size_t size = queue.size();
    for (size_t i = 0; i < size; ++i) {
        char c = queue.dequeue ();
        std::cout << c << ",";
    } // end for
    std::cout << std::endl;
} // end print Queue