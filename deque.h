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

class deque{
 private:
  int** blockmap;//Double array pointer
  int amount;
  int mapsize=10;//Amount of blocks
  const static int blocksize=20;//Amount of space in each block
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
  deque();//Constuctor
  ~deque();//Destructor

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
 * automatically enters values into deque
 *
 * @param int num amount of vaules to be entered
 * @pre 
 * @return void 
 * @post 
 * 
 */
  void autoenter(int num);

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
#endif
