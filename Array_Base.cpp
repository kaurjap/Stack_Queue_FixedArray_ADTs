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

} // end initialization constructor


//
// Array (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill)
    : data_ (new T [length]),
    cur_size_ (length),
    max_size_ (length)
{
    this->fill (fill);          // TRY: changing the parameter name "fill" (inconsistency with using "this" because didn't use it anywhere else)
} // end initialization constructor


//
// Array (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base <T> & array)
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
Array_Base <T>::~Array_Base (void)
{
    try {
        delete [] data_;
    } catch (...) {
        throw;          // IDEA: can throw a std::exception with a custom message?
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
    return find(value, 0);
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
    // assuming that "begin" is the zero based location of the starting element of the slice
    size_t subArray_size = cur_size_ - begin;
    Array_Base <T> subArray(subArray_size); // on the stack

    for (size_t i = begin; i < subArray_size; i++) {
        subArray[i-begin] = data_[i];
    } // end for

    return subArray;
} // end slice


//
// slice
//
template <typename T>
Array_Base <T> Array_Base <T>::slice (size_t begin, size_t end) const {
    // assuming that "begin" and "end" is the zero based location of the starting element of the slice
    size_t subArray_size = end - begin;
    Array_Base <T> subArray(subArray_size); // on the stack

    for (size_t i = begin; i < subArray_size; i++) {
        subArray[i-begin] = data_[i];
    } // end for

    return subArray;
} // end slice