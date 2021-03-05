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
    : Array <T> (N)
{

} // end default constructor 

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr)
    : Array <T> (N)
{
    // CODE REDUCTION: can also call the assignment operator because same behavior
    // *this = arr;

	for (size_t i = 0; i < N; i++) {
        data_[i] = arr.data_[i];            // POTENTIAL ERROR: data_ private member variable of Array and not Fixed_Array
    } // end for
} // end copy constructor (same sized arrays)

//
// Fixed_Array
// we'll copy the first N elements from the M sized array being set equal to
// N>M vs. M>N?
// use case:
//      Fixed_Array <int, 5> a1;
//      Fixed_Array <int, 7> a2 (a1);   N > M --> changes the first 5 elements of a1 into itself
//      Fixed_Array <int, 4> a3 (a1);   N < M --> copies the first 4 elements of a1 into itself
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
    : Array <T> (N)
{
    // CODE REDUCTION: can also call the assignment operator because same behavior
    // *this = rhs;

    // only copy the first N elements (or first M elements depending on which is smaller) from the M sized array (or N sized array) 
    size_t upper_bound = N;
    if (N > M) {
        upper_bound = M;
    } // end if
	for (size_t i = 0; i < upper_bound; i++) {
        data_[i] = arr.data_[i];            // POTENTIAL ERROR: data_ private member variable of Array and not Fixed_Array
    } // end for
} // end initialization constructor (different sized arrays)

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
    : Array <T> (N)
{
    this->fill (fill);
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
        data_[i] = rhs.data_[i];            // POTENTIAL ERROR: data_ private member variable of Array and not Fixed_Array
    } // end for
} // end operator = (same as copy constuctor)

//
// operator =
//
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
    // only copy the first N elements (or first M elements depending on which is smaller) from the M sized array (or N sized array) 
    size_t upper_bound = N;
    if (N > M) {
        upper_bound = M;
    } // end if
	for (size_t i = 0; i < upper_bound; i++) {
        data_[i] = rhs.data_[i];            // POTENTIAL ERROR: data_ private member variable of Array and not Fixed_Array
    } // end for
} // end operator = (same as different size initialization)
