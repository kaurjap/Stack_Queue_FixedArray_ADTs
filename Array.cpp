// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array <T>::Array (void)
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
{

}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill)
{

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array)
{

}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{

}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{

}

//
// operator []
//
template <typename T>
T & Array <T>::operator [] (size_t index)
{

}

//
// operator [] 
//
template <typename T>
const T & Array <T>::operator [] (size_t index) const
{

}

//
// get
//
template <typename T>
T Array <T>::get (size_t index) const
{

}

//
// set
//
template <typename T>
void Array <T>::set (size_t index, T value)
{

}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{

}

//
// find (char)
//
template  <typename T>
int Array <T>::find (T value) const
{

}

//
// find (char, size_t) 
//
template <typename T>
int Array <T>::find (T val, size_t start) const
{

}

//
// operator ==
//
template <typename T>
bool Array <T>::operator == (const Array & rhs) const
{

}

//
// operator !=
//
template <typename T>
bool Array <T>::operator != (const Array & rhs) const
{

}

//
// fill
//
template <typename T>
void Array <T>::fill (T value)
{

}
