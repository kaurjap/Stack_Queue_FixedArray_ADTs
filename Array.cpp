// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


//
// Array 
//
template <typename T>
Array <T>::Array (void)
    : Array_Base <T> ()
{

} // end default constructor


//
 // Array (size_t)
 //
 template <typename T>
 Array <T>::Array (size_t length)
     : Array_Base <T> (length)
 {

 } // end initialization constructor


 //
 // Array (size_t, T)
 //
 template <typename T>
 Array <T>::Array (size_t length, T fill)
     : Array_Base <T> (length, fill)
 {

 } // end initialization constructor


//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array <T> & array)
    : Array_Base <T> (array)
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
        if (this->max_size_ < rhs.cur_size_) {
            delete [] this->data_;
            this->data_ = new T [rhs.cur_size_];
            this->max_size_ = rhs.cur_size_;
        } // end if
        this->cur_size_ = rhs.cur_size_;
        for (size_t i = 0; i < rhs.cur_size_; i++) {
            this->data_[i] = rhs.data_[i];
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
    if (new_size < this->cur_size_ || new_size < this->max_size_) {
        this->cur_size_ = new_size;
    } else if (new_size > this->max_size_) {
        // create a new array with the bigger size
        T * new_array = new T [new_size];
        // copy all the existing elements to new array
        for (size_t i = 0; i < this->cur_size_; i++) {
            new_array[i] = this->data_[i];
        } // end for
        delete [] this->data_;
        this->data_ = new_array;
        this->cur_size_ = new_size;
        this->max_size_ = new_size;
    } // end if-else
} // end resize


// 
// shrink
//
template <typename T>
void Array <T>::shrink (void) {
    if (this->cur_size_ < this->max_size_) {
        T * new_array = new T [this->cur_size_];
        for (size_t i = 0; i < this->cur_size_; i++) {
            new_array[i] = this->data_[i];
        } // end for
        delete [] this->data_;
        this->data_ = new_array;
        this->max_size_ = this->cur_size_;
    } // end if
} // end shrink