// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
    : data_ (new T[5]),
    cur_size_ (0),
    max_size_ (5)
{

} // end default constructor


//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
    : data_ (new T [length]),
    cur_size_ (length),
    max_size_ (length)
{

} // end initialization constructor


//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
    : data_ (new T [length]),
    cur_size_ (length),
    max_size_ (length)
{
    this->fill (fill);          // TRY: changing the parameter name "fill" (inconsistency with using this)
} // end initialization constructor


//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
    : data_ (new T [array.max_size_]),
    cur_size_ (array.cur_size_),
    max_size_ (array.max_size_)
{
    for (size_t i = 0; i < array.cur_size_; i++) {
        data_[i] = array.data_[i]; 
    } // end for
} // end copy constructor


//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    try {
        delete [] data_;
    } catch (...) {
        throw;          // IDEA: can throw a std::exception with a custom message?
    } // end try-catch
} // end destructor


//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
    if (this == &rhs) {
        return *this;
    } // end if
    else {
        if (max_size_ < rhs.cur_size_) {
            delete [] data_;
            data_ = new T [rhs.cur_size_];
            max_size_ = rhs.cur_size_;
        } // end if
        cur_size_ = rhs.cur_size_;
        for (size_t i = 0; i < rhs.cur_size_; i++) {
            data_[i] = rhs.data_[i];
        } // end for
        return *this;
    } // end if-else
} // end operator =


//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{
    if (cur_size_ <= index) {
        throw std::out_of_range("std::out_of_range: The index passed in is greater than the size of the array.");
    } else {
        return data_[index];
    } // end if-else
} // end operator [] for mutability


//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{
    if (cur_size_ <= index) {
        throw std::out_of_range("std::out_of_range: The index passed in is greater than the size of the array.");
    } else {
        return data_[index];
    } // end if-else
} // end operator [] for access


//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{
    if (cur_size_ <= index) {
        throw std::out_of_range("std::out_of_range: The index passed in is greater than the size of the array.");
    } else {
        return data_[index];
    } // end if-else
} // end get


//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{
    if (cur_size_ <= index) {
        throw std::out_of_range("std::out_of_range: The index passed in is greater than the size of the array.");
    } else {
        data_[index] = value;
    } // end if-else
} // end set


//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
    if (new_size < cur_size_ || new_size < max_size_) {
        cur_size_ = new_size;
        // max_size and data_ remain the same, only less elements are accessible now
    
    } else if (new_size > max_size_) {
        // create a new array with the bigger size
        T * newArray = new T [new_size];
        // copy all the existing elements to new array
        for (size_t i = 0; i < cur_size_; i++) {
            newArray[i] = data_[i];     // TRY: newArray->data_[i] directly, don't know if this would work since it is a pointer
        } // end for
        delete [] data_;
        data_ = newArray;
        cur_size_ = new_size;
        max_size_ = new_size;
    } // end if-else
} // end resize


//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{
    return find(value, 0);
} // end find 


//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{
    int returnVal = -1;
    if (start >= cur_size_) {
        throw std::out_of_range("std::out_of_range: The start index is larger than the size of the array");
    } else {
        for (size_t i = start; i < cur_size_; i++) {
            if (data_[i] == val) {
                returnVal = (int) i;
                break;
            } // end if
        } // end for
    } // end if-else
    return returnVal;
} // end find with start


//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{
    bool returnVal = true;
    if (this == &rhs) {
        returnVal = true;
    } else {
        if (cur_size_ == rhs.cur_size_) {
            for (size_t i = 0; i < cur_size_; i++) {
                if (data_[i] != rhs.data_[i]) {
                    returnVal = false;
                    break;
                } // end if
            } // end for
        } else {
            returnVal = false;
        } // end if-else
    } // end else
    return returnVal;
} // end operator == 


//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{
    return !((*this) == rhs);
} // end operator !=


//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{
    for (size_t i = 0; i < cur_size_; i++) {
        data_[i] = value;
    } // end for
} // end fill


template <typename T>
void Array <T>::shrink (void) {
    if (cur_size_ < max_size_) {
        T * newArray = new T [cur_size_];
        for (size_t i = 0; i < cur_size_; i++) {
            newArray[i] = data_[i];
        } // end for
        delete [] data_;
        data_ = newArray;
        max_size_ = cur_size_;
    } // end if
} // end shrink


template <typename T>
void Array <T>::reverse ( void ) {
    T temp;
    for (size_t i = 0; i < (cur_size_/2); i++) {
        temp = data_[i];
        data_[i] = data_[cur_size_ - 1 - i];
        data_[cur_size_ - 1 - i] = temp;
    } // end for
} // end reverse


template <typename T>
Array <T> Array <T>::slice (size_t begin) const {
    // assuming that "begin" is the zero based location of the starting element of the slice
    size_t subArray_size = cur_size_ - begin;
    Array <T> subArray(subArray_size); // on the stack

    for (size_t i = begin; i < subArray_size; i++) {
        subArray[i-begin] = data_[i];
    } // end for

    return subArray;
} // end slice


template <typename T>
Array <T> Array <T>::slice (size_t begin, size_t end) const {
    // assuming that "begin" and "end" is the zero based location of the starting element of the slice
    size_t subArray_size = end - begin;
    Array <T> subArray(subArray_size); // on the stack

    for (size_t i = begin; i < subArray_size; i++) {
        subArray[i-begin] = data_[i];
    } // end for

    return subArray;
} // end slice