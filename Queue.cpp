// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


template <typename T>
Queue <T>::Queue (void)
    : array_ (new Array <T> ())
{

} // end default constructor


template <typename T>
Queue <T>::Queue (const Queue & queue)
    : array_ (new Array <T> (queue.size())) 
{
    array_ = queue.array_;
} // end copy constructor


template <typename T>
Queue <T>::~Queue (void)
{
    try {
        delete array_;
    } catch (...) {
        throw;
    } // end try-catch
} // end destructor


template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    array_ = rhs.array_;
    return *this;
} // end operator =


template <typename T>
void Queue <T>::enqueue (T element)
{
    array_->resize(size() + 1);
    // size is now updated with the new size, hence
    array_[size()] = element;
} // end enqueue

template <typename T>
T Queue <T>::dequeue (void)
{
    T returnVal = array_[0];
    if (is_empty()) {
        empty_exception ex;
        throw ex;
    } // end if
    else {
        for (size_t i = 0; i < size() - 1; i++) {
            array_[i] = array_[i+1];
        } // end for
        array_->resize(size() - 1);
    } // end else
    return returnVal;
} // end dequeue


template <typename T>
void Queue <T>::clear (void)
{
    array_->resize(0);
} // end clear
