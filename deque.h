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
  int** blockmap;
  int amount;
  int mapsize=10;
  const static int blocksize=20;
  int firstblock;
  int firstelement;
  void resize();
 public:
  deque();
  ~deque();
  void push_front(int num);
  void push_back();
  void pop_front();
  void pop_back();
  int front();
  int back();
  bool empty();
  int size();
  int& operator[](unsigned int index);
};
#endif
