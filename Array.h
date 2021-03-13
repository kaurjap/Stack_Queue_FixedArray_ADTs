// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */ 
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Array_Base.h"

/**
 * @class Array
 * 
 * Implementation of a template based Array. It is derived from Array_Base to inherit all
 * of the base functionality of an array. It contains additional methods of its own that provide
 * it the functionality that distinguishes it from the Fixed_Array allowing it to resize and
 * shrink itself.
 * 
 */
template <typename T>
class Array : public Array_Base <T>
{
public:
  /// Type definition of the element type.
  typedef T type;

  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array (const Array & arr);

  /// Destructor.
  ~Array (void);

  /**
   * Assignment operation
   *
   * @param[in]       rhs      Right-hand side of equal sign
   * @return          Reference to self
   */
  const Array & operator = (const Array & rhs);

  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the 
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize (size_t new_size);

  /// Shrink the array to reclaim unused space.
  void shrink ( void );

};

#include "Array.inl"
#include "Array.cpp"

#endif   // !defined _ARRAY_H_