// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array <T> & array)
    : Array_Base <T> (array)        // calling the base copy constructor
{
    
} // end copy constructor


//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
    // nothing allocated in the derived class
} // end destructor


//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array <T> & rhs)
{
    if (this == &rhs) {
        return *this;
    } // end if
    else {
        if (max_size_ < rhs.cur_size_) {
            delete [] this->data_;
            this->data_ = new T [rhs.cur_size_];
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
// shrink
//
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