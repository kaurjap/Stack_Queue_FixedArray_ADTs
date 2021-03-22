// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
    return array_.size ();
} // end size

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
    if (is_empty()) {
        empty_exception ex;
        throw ex;
    } else {
        // return the lastly added element  
        return array_.get (array_.size() - 1);  
    } // end if-else
} // end top

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
    if (array_.size () == 0) {
        return true;
    } else {
        return false;
    } // end if-else
} // end is_empty
