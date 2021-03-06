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
    // since the stack is basically the array_, its cur_size_, and max_size_
    // just assigning the passed in stack's array to this stack's array

    // CODE REDUCTION: can also just call the assignment operator --> seems more expensive 
    // *this = stack;

    // i am also able to access stack's private members directly
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
