// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
    : array_ (new Array <T> ())
{

} // end default constructor

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : array_ (new Array <T> (stack.size()))
{
    // since the stack is basically the array_, array_'s cur_size_ and max_size_
    // just assigning the passed in stack's array to this stack's array

    // also able to access stack's private members directly
    array_ = stack.array_;
} // end copy constructor

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    try {
        delete array_;
    }
    catch (...) {
        throw;
    } // end try-catch
} // end destructor

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // COMMENT You current design of the stack is copying each element
    // over on location each time your push a new element onto the stack.
    // Unfortunately, this is an expensive operation—--especially if you
    // have a large number of elements on the stack. Improve your design
    // so that you are not copying each element every time you push a new
    // element onto the stack.
    
    // if the array- has space to insert another element, then insert it
    // otherwise, allocate space and then insert the element
    // resize method does just that
    array_->resize (size() + 1);

    // move the current elements to the right by one
    for (size_t i = (size() - 1); i > 0; i--) {  // size() is also updated
        array_[i] = array_[i-1];
    } // end for

    // insert the element on the top
    array_[0] = element;
} // end push

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
    if (is_empty()) {
        empty_exception ex;
        throw ex;
    } else {
        // COMMENT You current design of the stack is copying each element
        // over on location each time your pop a new element from the stack.
        // Unfortunately, this is an expensive operation—--especially if you
        // have a large number of elements on the stack. Improve your design
        // so that you are not copying each element every time you pop a new
        // element from the stack.
        
        // move the array elements to the left by one
        for (size_t i = 0; i < size() - 1; i++) {
            array_[i] = array_[i+1];
        } // end for

        // set the array_ size to be less by one which automatically reflects on the stack size
        array_->resize(size()-1);
    } // end if-else
} // end pop

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // COMMENT Always check for self-assignment first before continuing.

    // COMMENT Your code will eventually crash since stacks will be sharing
    // the same array allocation.
    array_ = rhs.array_;
    return *this;
} // end operator =

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    array_->resize(0);
} // end clear
