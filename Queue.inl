// -*- C++ -*-

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.


template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    if (size() == 0) {
        return true;
    } else {
        return false;
    } // end if-else
} // end is_empty


template <typename T>
inline
size_t Queue <T>::size (void)
{
    return array_->size();
} // end size