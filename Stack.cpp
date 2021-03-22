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
    : array_ (Array <T> ())
{

} // end default constructor

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack)
    : array_ (Array <T> (stack.size()))
{
    // since the stack is basically the the state of the array object
    // just assigning the passed in stack's array to this stack's array
    array_ = stack.array_;
} // end copy constructor

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
    // nothing allocated on the heap in this class
} // end destructor

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
    // COMMENT You current design of the stack is copying each element
    // over one location each time your push a new element onto the stack.
    // Unfortunately, this is an expensive operation—--especially if you
    // have a large number of elements on the stack. Improve your design
    // so that you are not copying each element every time you push a new
    // element onto the stack.
    // SOLUTION This method was initially a misunderstanding on my part 
    // about the push method. I mis-imagined the top of the stack to be 
    // represented by the beginning of the array. Meaning, that instead of 
    // adding to the top of the stack, I was adding to the bottom of the stack.
    // So, I resolved this issue by adding an element to the end of the array 
    // representing the stack.

    array_.resize (array_.size() + 1);
    // size of the array, and hence the stack, are now incremented by 1
    array_[array_.size() - 1] = element; 
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
        // over one location each time your pop a new element from the stack.
        // Unfortunately, this is an expensive operation—--especially if you
        // have a large number of elements on the stack. Improve your design
        // so that you are not copying each element every time you pop a new
        // element from the stack.
        // SOLUTION This method was initially a misunderstanding on my part 
        // about the pop method. Instead of deleting the lastly added element 
        // from the stack, which is its top (following the LIFO access structure),
        //  I was deleting the first added element from the stack. Hence, Dr. Hill,
        // I resolved this issue by deleting the last element from the stack's array,
        // basically by resizing the stack to one size less.

        array_.resize (array_.size() - 1);
    } // end if-else
} // end pop

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
    // COMMENT Always check for self-assignment first before continuing.
    // SOLUTION Dr. Hill, I resolved this comment by including an if branch to 
    // return the current object itself if it is being assigned to itself.

    // COMMENT Your code will eventually crash since stacks will be sharing
    // the same array allocation.
    // SOLUTION Dr. Hill, I resolved this comment by allocating the array the 
    // stack so they don't share the same pointer values when assigning one 
    // array to the other.

    if (this == &rhs) {
        // do not modify the state of the object
    } else {
        array_ = rhs.array_;
    } // end if-else
    return *this;
} // end operator =

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
    array_.resize(0);
} // end clear
