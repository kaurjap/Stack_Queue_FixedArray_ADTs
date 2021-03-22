// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


//
// Array
//
template <typename T>
Array_Base <T>::Array_Base (void)
    : data_ (new T [5]),
    cur_size_ (0),
    max_size_ (5)
{  
    // nothing needs to be done
} // end default constructor


//
// Array (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length)
    : data_ (new T [length]),
    cur_size_ (length),
    max_size_ (length)
{
    // nothing needs to be done
} // end initialization constructor


//
// Array (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T element)
    : Array_Base <T> (length)
{
    fill (element);
} // end initialization constructor


//
// Array (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base <T> & array)
    : Array_Base <T> (array.cur_size_)
{
    for (size_t i = 0; i < array.cur_size_; i++) {
        data_[i] = array.data_[i]; 
    } // end for
} // end copy constructor


//
// ~Array
//
template <typename T>
Array_Base <T>::~Array_Base (void)
{
    try {
        delete [] data_;
    } catch (...) {
        throw;
    } // end try-catch
} // end destructor


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
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
const T & Array_Base <T>::operator [] (size_t index) const
{
    // reuse of code -- mobility
   return this[index];
} // end operator [] for access


//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
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
void Array_Base <T>::set (size_t index, T value)
{
    if (cur_size_ <= index) {
        throw std::out_of_range("std::out_of_range: The index passed in is greater than the size of the array.");
    } else {
        data_[index] = value;
    } // end if-else
} // end set


//
// find (char)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
    try {
        return find(value, 0);
    } catch (const std::out_of_range & ex) {
        // since this method doesn't take in an index, the exception means just return -1
        return -1;
    } // end try-catch
} // end find 


//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
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
bool Array_Base <T>::operator == (const Array_Base <T> & rhs) const
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
bool Array_Base <T>::operator != (const Array_Base <T> & rhs) const
{
    return !((*this) == rhs);
} // end operator !=


//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
    for (size_t i = 0; i < cur_size_; i++) {
        data_[i] = value;
    } // end for
} // end fill

//
// reverse
//
template <typename T>
void Array_Base <T>::reverse ( void ) {
    T temp;
    for (size_t i = 0; i < (cur_size_/2); i++) {
        temp = data_[i];
        data_[i] = data_[cur_size_ - 1 - i];
        data_[cur_size_ - 1 - i] = temp;
    } // end for
} // end reverse


//
// slice
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin) const {
    // same as the slice method with begin and end index, with end being equal to the size of the array
    Array_Base <T> subArray = slice (begin, cur_size_-1);
    return subArray;
} // end slice


//
// slice
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const {
    if (begin > cur_size_ - 1 || end > cur_size_ - 1) {
        throw std::out_of_range("std::out_of_range: Either or both indexes passed in are greater than the size of the array.");
    } else {
        // assuming that "begin" and "end" is the zero based location of the starting element of the slice
        size_t subArray_size = end - begin;
        Array_Base <T> subArray(subArray_size); // on the stack

        for (size_t i = begin; i < subArray_size; i++) {
            subArray[i-begin] = data_[i];
        } // end for

        return subArray;
    } // end if-else
} // end slice
