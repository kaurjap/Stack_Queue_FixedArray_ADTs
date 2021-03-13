// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void)
    : Array_Base <T> (N)
{

} // end default constructor 


//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
    : Array_Base <T> (N)
{
	for (size_t i = 0; i < N; i++) {
        this->data_[i] = arr.data_[i];     
    } // end for
} // end copy constructor (same sized arrays)


//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
    : Array_Base <T> (N, fill)
{
    
} // end initialization constructor (with fill)


//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
    // no memory allocated in the derived class 
    // automatically calls the base's destructor
} // end destructor


//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	for (size_t i = 0; i < N; i++) {
        this->data_[i] = rhs.data_[i];           
    } // end for
    return *this;
} // end operator = (same as copy constuctor)