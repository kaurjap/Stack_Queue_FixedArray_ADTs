// -*- C++ -*-

//==============================================================================
/** 
 * @file       Queue.h
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */ 
//==============================================================================


#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Array.h"
#include <exception> // for empty-exception

/**
 * @class Queue
 *
 * Basic queue for abitrary elements.
 */
template <typename T>
class Queue
{
    public:
        typedef T type;

        /**
         * @class empty_exception
         *
         * Exception thrown to indicate the Queue is empty.
         */
        class empty_exception : public std::exception
        {
        public:
            /// Default constructor.
            empty_exception (void)
            : std::exception () { }

            /**
             * Initializing constructor.
             *
             * @param[in]      msg         Error message.
             */
            //empty_exception (const char * msg)
            //: std::exception (msg) { }
        
            const char * what() 
            {
                return "empty_exception: The queue is empty.";
            } // end what()
            
        };

        /// Default constructor
        Queue (void);

        /// Copy constructor
        Queue (const Queue & queue);

        /// Destructor
        ~Queue (void);

        /**
         * Assignment operator
         *
         * @param[in]      rhs              Right-hand side of operator
         * @return         Reference to self
         */
        const Queue & operator = (const Queue & rhs);

        /**
         * Add an element to the end of the list
         * 
         * @param[in]       element         Element to add to the list
         */
        void enqueue (T element);

        /**
         * Remove the element at the front of the list
         * 
         * @return         Element at the front of the list
         * @exception      empty_exception The queue is empty
         */ 
        T dequeue (void);

        /**
         * Test if the queue is empty
         *
         * @retval         true          The queue is empty
         * @retval         false         The queue is not empty
         */
        bool is_empty (void) const;

        /**
         * Number of elements on the queue.
         *
         * @return         Size of the queue.
         */
        size_t size (void) const;

        /// Remove all elements from the stack.
        void clear (void);


    private:
    // COMMENT There is no need to allocate the array on the heap. Always try to
    // allocate on the stack to reduce the complexity of your code.
    // SOLUTION Dr. Hill, I resolved this comment by allocating the array on the stack.

        // aggregation
        Array <T> array_;
};

#include "Queue.inl"
#include "Queue.cpp"

#endif  // !defined _QUEUE_H_
