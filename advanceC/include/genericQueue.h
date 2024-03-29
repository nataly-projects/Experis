/** 
 * @brief Create a Generic Queue data type of a given size
 * that stores pointer to user provided elements of generic type
 * The Queue is heap allocated and wraps around
 * 
 * @author Author Nataly.
 */ 
#ifndef __GENERICQUEUE_H__
#define __GENERICQUEUE_H__
#include <stdlib.h>


#define TRUE 1
#define FALSE 0

typedef struct Queue Queue;
typedef int	(*QueueElementAction)(void* _element, size_t _index, void* _context);

typedef enum Queue_Result {
	QUEUE_SUCCESS,
	QUEUE_UNINITIALIZED_ERROR,				/**< Uninitialized queue error 	*/
	QUEUE_OVERFLOW,							/**< Queue is full for insert operation */
	QUEUE_UNDERFLOW,						/**< Queue is empty for remove operation */
	QUEUE_NULL_ELEMENT_ERROR							
} Queue_Result;

/* 
 * @brief Dynamically create a new queue object of given size.
 * @param[in] _maxSize - maximal number of elements that can be stored in the queue.
  * @return Queue * - on success / NULL on fail. 
 *
 * @warning if _maxSize is zero function will return NULL.
 */
Queue* Queue_Create(size_t _maxSize);


/*  
 * @brief Dynamically deallocate a previously allocated vector.  
 * @param[in] _queue - Vector to be deallocated.
 * @params[in] _elementDestroy : A function pointer to be used to destroy all
 * 					 remaining elements in the queue or a null if no such destroy is required
 * @return void
 */
void Queue_Destroy(Queue** _queue, void (*_elementDestroy)(void* _item));


/* 
 * @brief Enqueue an Item to the tail of the Queue.  
 * @param[in] _queue - Queue to operate on.
 * @param[in] _item - Item to enqueue.
 * @return success or error code: 
 * @retval QUEUE_SUCCESS on success 
 * @retval QUEUE_UNINITIALIZED_ERROR if _queue is NULL. 
 * @retval QUEUE_OVERFLOW - if the queue is full.
 * @retval QUEUE_NULL_ELEMENT_ERROR - if the _item is NULL.
 * @warning _item can't be null. this will be assertion violation
 */
Queue_Result Queue_Enqueue(Queue* _queue, void* _item);



/*  
 * @brief Dequeue Remove item at head of queue or return an error if queue is empty.  
 * @param[in] _queue - Queue to operate on.
 * @param[out] _pValue - pointer to variable that will receive dequeued item
 * @return success or error code 
 * @retval QUEUE_SUCCESS on success 
 * @retval QUEUE_UNINITIALIZED_ERROR - if queue is NULL.
 * @retval QUEUE_NULL_ELEMENT_ERROR - if the _pValue is NULL.
 * @retval QUEUE_UNDERFLOW - if the queue is empty.
 */
Queue_Result Queue_Dequeue(Queue* _queue, void** _pValue);

/*  
 * @brief Return true if the queue is empty.
 * @param[in] _queue - Queue to check.
 * @return  1 if empty 0 otherwise
 */
int Queue_IsEmpty(const Queue* _queue);

/*
 * The following are convenience functions for debugging purposes
 */
/**  
 * @brief Iterate over all elements in the queue.
 * @details The user provided _action function will be called for each element
 *          if _action return a zero for an element the iteration will stop.  
 * @param[in] _queue  - queue to iterate over.
 * @param[in] _action - User provided function pointer to be invoked for each element
 * @param[in] _context - User provided context, will be sent to _action
 * @returns number of times the user functions was invoked, or 0 if _queue is NULL.
 * 
 * Example use: Queue_ForEach(queue, PrintElement, NULL)
 */
size_t Queue_ForEach(const Queue* _queue, QueueElementAction _action, void* _context);




#endif /*__GENERICQUEUE_H__*/ 
