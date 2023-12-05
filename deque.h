/**
 * @file deque.h
 * @author Kevin Austin
 * @date 2023-12-01
 * @brief Deque class header
 * 
 * Declares all objects for the custom deque class
 */

#ifndef DEQUE_H
#define DEQUE_H



/**
 * This class represents a deque (double ended queue)
 *
 * @class deque{ deque.h "Deque/deque.h"
 * @brief Deque class
 *
 */
class deque{
 private:
  int** blockmap; //The blockmap (Double array pointer)
  int amount; //The total amount of elements in the blockmap (it would be called 'size', but we called it 'amount' since 'size' is a method name)
  int mapsize = 10; //Initial Amount of blocks, which we chose to make 10
  const static int blocksize = 20; //Amount of space in each block which we chose to make 20
  int firstblock;//Leftmost used block
  int firstelement;//Leftmost used element in firstblock

/**
 * Resizes the deque
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void resize();
  
 public:

/**
 * Class constructor
 *
 * @pre 
 * @post First block and first element have been set, memory has been allocated
 * 
 */
  deque();
  

/**
 * Destructor - deallocates memory
 *
 * @pre 
 * @post Memory has been deallocated
 * 
 */
  ~deque();

/**
 * Pushes given value to front of deque
 *
 * @param int num Value to be pushed
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_front(int num);

/**
 * Pushes value to end of deque
 *
 * @param int num value to be pushed
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void push_back(int num);

/**
 * gets rid of frontmost value
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pop_front();

/**
 * gets rid of backmost value
 *
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void pop_back();

/**
 * returns frontmost value
 *
 * @pre 
 * @return int frontmose value
 * @post 
 * 
 */
  int front();

/**
 * returns backmost value
 *
 * @pre 
 * @return int backmost value
 * @post 
 * 
 */
  int back();

/**
 * Checks whether or not deque is empty
 *
 * @pre 
 * @return bool whether or not empty
 * @post 
 * 
 */
  bool empty();

/**
 * returns the size of the deque
 *
 * @pre 
 * @return int 
 * @post 
 * 
 */
  int size();

/**
 * overloads [] operator to give access to deque without using d[][] for example
 *
 * @param unsigned int index 
 * @pre 
 * @return int& position on deque
 * @post 
 * 
 */
  int& operator[](unsigned int index);
};
#endif //DEQUE_H
