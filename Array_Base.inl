// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.


template <typename T>
inline
size_t Array_Base <T>::size (void) const
{
    return cur_size_;
} // end size


template <typename T>
inline
size_t Array_Base <T>::max_size (void) const
{
    return max_size_;
} // end max_size_
