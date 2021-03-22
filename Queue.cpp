// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


template <typename T>
Queue <T>::Queue (void)
    : array_ (Array <T> ())
{

} // end default constructor


template <typename T>
Queue <T>::Queue (const Queue & queue)
    : array_ (Array <T> (queue.size())) 
{
    // COMMENT Your code will eventually crash since queue will be sharing
    // the same array allocation.
    // SOLUTION Dr. Hill, I resolved this issue by allocating the array on the stack.

    array_ = queue.array_;
} // end copy constructor


template <typename T>
Queue <T>::~Queue (void)
{
    // nothing allocated in this class to delete
} // end destructor


template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    // COMMENT Always check for self assignment.
    // SOLUTION Dr. Hill, I resolved this issue by adding an if branch that returns the
    // self (this) pointer if the object is being assigned to itself.
    
    // COMMENT Your code will eventually crash since queue will be sharing
    // the same array allocation.
    // SOLUTION Dr. Hill, I resolved this issue by allocating the array on the stack.

    if (this == &rhs) {
        // do nothing
    } else {
        // change the current array to be equal to passed in array
        array_ = rhs.array_;
    } // end if-else
    return *this;
} // end operator =


template <typename T>
void Queue <T>::enqueue (T element)
{
    array_.resize (array_.size() + 1);
    // size is now updated with the new size, hence
    array_ [array_.size() - 1] = element;
} // end enqueue

template <typename T>
T Queue <T>::dequeue (void)
{
    if (is_empty()) {
        empty_exception ex;
        throw ex;
    } // end if
    else {
        T first_element = array_[0];
        // COMMENT This design is OK, but it is not the best design. This will be
        // a very expensive array to use if you are dequeing a lot of elements. This
        // is because you are copying N elements each time you dequeue 1 element.
        // Instead, you only want to copy element when necessary. Come up with a better
        // design that is not as expensive for the client to use.
        // SOLUTION Dr. Hill, instead of copying each element over to dequeue one element
        // each time, I used the existing reverse method of the array to delete the element using 
        // the resize method and then reversing back the contents again. However, it is not
        // any better in terms of performance, now that I think about it, because the reverse 
        // method also makes copies of elements to move them around. It just makes the design look cleaner.

        array_.reverse ();
        array_.resize (array_.size () - 1);
        array_.reverse ();
        return first_element;
    } // end else
} // end dequeue


template <typename T>
void Queue <T>::clear (void)
{
    array_.resize (0);
} // end clear
