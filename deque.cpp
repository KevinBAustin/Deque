/**
 * @file deque.cpp
 * @author Kevin Austin
 * @date 2023-12-01
 * @brief Class Defintion file
 * 
 * Defines all objects in the custom deque class
 */
#include "deque.h"
#include <iostream>

using namespace std;

void deque::resize(){
  cout << "Resize called" << endl;
  int ** temp;
  mapsize+=2;
  temp = new int* [mapsize];

  temp[0] = new int[blocksize];

  for (int i = 0; i < mapsize; i++){
    temp[i+1] = blockmap[i];
  }
  temp[mapsize - 1] = new int[blocksize];
  temp[mapsize - 2] = new int[blocksize];

  delete[] blockmap;
  blockmap = temp;
}

deque::deque(){
  firstblock = 2;
  firstelement = 2;
  blockmap = new int* [mapsize];
  for (int i = 0; i < mapsize; i++){
    blockmap[i] = new int[blocksize];
  }
}


deque::~deque(){
  for (int i = 0; i < mapsize; i++){
    delete[] blockmap[i];
  }

  delete[] blockmap;
}

void deque::push_front(int num){
  if (firstelement == 0 && firstblock == 0){
    resize();
    firstblock = 1;
    firstelement=blocksize-1;
    blockmap[firstblock][firstelement] = num;
    amount++;
  }
  else if (firstelement == 0){
    blockmap[firstblock][firstelement] = num;
    amount++;
    firstblock = firstblock-1;
    firstelement = blocksize;
  }
  else {
    firstelement = firstelement-1;
    blockmap[firstblock][firstelement] = num;
    amount++;
  }
}

void deque::push_back(int num){
  int row;
  int col;
  row = firstblock + ((firstelement + amount)/blocksize);
  col = (firstelement + amount) % blocksize;
  if (amount == 0) {
  blockmap[firstblock][firstelement] = num;
  }
  else if (row == mapsize-1){
    blockmap[mapsize-1][blocksize-1] = num;
    resize();
  }
  else if (col == blocksize-1){
    blockmap[row][blocksize-1] = num;
  }
  else {
    blockmap[row][col] = num;
  }
    amount++;
}

void deque::pop_front(){
  if (firstblock == mapsize-1 && firstelement == blocksize - 1){
    blockmap[firstblock][firstelement] = 0;
    amount--;
  }
  else {
    if (firstelement != blocksize-1){
      blockmap[firstblock][firstelement] = 0;
      amount--;
      firstelement+=1;
    }
    else {
      blockmap[firstblock][firstelement] = 0;
      amount--;
      firstblock+=1;
    }
  }
}

void deque::pop_back(){
  
}

int deque::front(){
  return blockmap[firstblock][firstelement];
}

int deque::back(){
  int row;
  int col;
  row = firstblock + ((firstelement + amount)/blocksize);
  col = (firstelement + amount) % blocksize;
  return blockmap[row][col-1];
}

bool deque::empty(){
}

int deque::size(){
  return amount;
}

int& deque::operator[](unsigned int index){
  int row;
  int col;
  row = firstblock + ((firstelement + index)/blocksize);
  col = (firstelement + index) % blocksize;
  return blockmap[row][col];
}
